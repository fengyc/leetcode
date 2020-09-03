#include <stdlib.h>

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

    int deepesLeft(TreeNode *root, int *level) {
        if (root->left == NULL && root->right == NULL) {
            *level = 1;
            return root->val;
        }

        int vl, dl = 0;
        if (root->left) {
            vl = deepesLeft(root->left, &dl);
        }

        int vr, dr = 0;
        if (root->right) {
            vr = deepesLeft(root->right, &dr);
        }

        if (dl >= dr) {
            *level = dl + 1;
            return vl;
        }

        *level = dr + 1;
        return vr;
    }

    int findBottomLeftValue(TreeNode *root) {
        int level = 0;
        return deepesLeft(root, &level);
    }
};

int main() {
    Solution s;



    return 0;
}
