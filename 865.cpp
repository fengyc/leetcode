#include <vector>

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

    TreeNode *deepest(TreeNode *root, int *deepth) {
        if (root == NULL) {
            *deepth = 0;
            return NULL;
        }
        TreeNode *l = NULL, *r = NULL;
        int dl, dr;
        l = deepest(root->left, &dl);
        r = deepest(root->right, &dr);
        if (dl > dr) {
            *deepth = dl + 1;
            return l;
        }
        if (dr > dl) {
            *deepth = dr + 1;
            return r;
        }
        *deepth = dl+1;
        return root;
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        int deepth;
        return deepest(root, &deepth);
    }
};


int main() {

    Solution s;

    TreeNode n[9] = {(0), (1), (2), (3), (4), (5), (6), (7), (8)};
    n[3].left = &n[5];
    n[3].right = &n[1];
    n[5].left = &n[6];
    n[5].right = &n[2];
    n[2].left = &n[7];
    n[2].right = &n[4];
    n[1].left = &n[0];
    n[1].right = &n[8];

    TreeNode *root = &n[3];

    TreeNode *r = s.subtreeWithAllDeepest(root);

    return 0;

}
