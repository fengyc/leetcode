#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> r;
        while (root) {
            if (root->left) {
                s.push(root);
                root = root->left;
            } else {
                r.push_back(root->val);
                root = root->right;
                while (!root && !s.empty()) {
                    root = s.top();
                    s.pop();
                    r.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return r;
    }
};

int main() {

    Solution s;

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);

    n1->right = n2;
    n2->left = n3;

    vector<int> r = s.inorderTraversal(n1);

    return 0;
}
