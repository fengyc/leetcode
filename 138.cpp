#include <map>

using namespace std;


/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:

    map<Node *, Node *> m;

    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }
        auto search = m.find(head);
        if (search != m.end()) {
            return search->second;
        }
        Node *n = new Node(head->val, nullptr, nullptr);
        m.insert(make_pair(head, n));
        n->next = copyRandomList(head->next);
        n->random = copyRandomList(head->random);
        return n;
    }
};

