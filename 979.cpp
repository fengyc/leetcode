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

    int dis(TreeNode *root, int *r) {
        if (root == NULL) {
            *r = 0;
            return 0;
        }

        int remains=0;
        int moves = dis(root->left, &remains);
        root->val += remains;
        moves += abs(remains);

        moves += dis(root->right, &remains);
        root->val += remains;
        moves += abs(remains);

        *r = root->val - 1;

        return moves;
    }

    int distributeCoins(TreeNode *root) {
        int r = 0;
        return dis(root, &r);
    }
};

int main() {
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(0);
    r->right = new TreeNode(0);
    r->left->right = new TreeNode(3);

    Solution s;

    int n = s.distributeCoins(r);

    return 0;
}