#include <vector>
#include <map>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:

    map<Node *, Node *> m;

    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        auto search = m.find(node);
        if (search != m.end()) {
            return search->second;
        }
        vector<Node *> neighbours(node->neighbors.size());
        Node *n = new Node(node->val, neighbours);
        m.insert(make_pair(node, n));
        for (int i=0;i<node->neighbors.size();i++) {
            n->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        return n;
    }
};

int main() {
    Solution s;

    Node *n1 = new Node(1, {});
    Node *n2 = new Node(2, {});
    Node *n3 = new Node(3, {});
    Node *n4 = new Node(4, {});

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);
    
    Node *r = s.cloneGraph(n1);

    return 0;
}