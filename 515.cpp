
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> r;
        if (root == NULL) {
            return r;
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int m = q.front()->val;
            while (size--) {
                TreeNode *n = q.front();
                m = max(m, n->val);
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
                q.pop();
            }
            r.push_back(m);
        }
        return r;
    }
};

int main() {

    Solution s;

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n3 = new TreeNode(3);
    n3->left = new TreeNode(5);
    n3->right = new TreeNode(3);
    TreeNode *n2 = new TreeNode(2);
    n2->right = new TreeNode(9);
    n1->left = n3;
    n1->right = n2;

    vector<int> r = s.largestValues(n1);

    return 0;
}