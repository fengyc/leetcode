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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            if (root1->val != root2->val) {
                return false;
            }
            bool ll = flipEquiv(root1->left, root2->left);
            if (!ll) {
                bool lr = flipEquiv(root1->left, root2->right);
                if (!lr) {
                    return false;
                }
                bool rl = flipEquiv(root1->right, root2->left);
                if (!rl) {
                    return false;
                }
                return true;
            }
            bool rr = flipEquiv(root1->right, root2->right);
            if (!rr) {
                return false;
            }
            return true;
        } else return !(root1 || root2);
    }
};

int main() {
    // left
    TreeNode *n5 = new TreeNode(5);
    n5->left = new TreeNode(7);
    n5->right = new TreeNode(8);
    TreeNode *n2 = new TreeNode(2);
    n2->left = new TreeNode(4);
    n2->right = n5;
    TreeNode *n3 = new TreeNode(3);
    n3->left = new TreeNode(6);
    TreeNode *n1 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;

    // right
    TreeNode *r5 = new TreeNode(5);
    r5->left = new TreeNode(8);
    r5->right = new TreeNode(7);
    TreeNode *r2 = new TreeNode(2);
    r2->left = new TreeNode(4);
    r2->right = r5;
    TreeNode *r3 = new TreeNode(3);
    r3->right = new TreeNode(6);
    TreeNode *r1 = new TreeNode(1);
    r1->left = r3;
    r1->right = r2;

    Solution s;

    bool c = s.flipEquiv(n1, r1);

    return 0;
}