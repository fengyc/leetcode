#include <stdlib.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *pruneTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->left || root->right) {
            return root;
        }

        if (root->val == 0) {
            return NULL;
        }

        return root;
    }
};

int main() {

    TreeNode *n = new TreeNode(1);
    n->right = new TreeNode(0);
    n->right->left = new TreeNode(0);
    n->right->right = new TreeNode(1);

    Solution s;

    TreeNode *r = s.pruneTree(n);

    return 0;
}