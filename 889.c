#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode *constructFromPrePost(int *pre, int preSize, int *post, int postSize) {
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
    root->val = pre[0];

    if (preSize > 1) {
        int leftVal = pre[1];
        int rightVal = post[postSize - 2];
        // only one child
        if (leftVal == rightVal) {
            root->left = constructFromPrePost(pre + 1, preSize - 1, post, postSize - 1);
            return root;
        }
        // multi child
        int leftPreSize = 1;
        for (int i = 2; pre[i] != rightVal; i++) {
            leftPreSize++;
        }
        root->left = constructFromPrePost(pre + 1, leftPreSize, post, leftPreSize);
        root->right = constructFromPrePost(pre + 1 + leftPreSize, preSize - leftPreSize - 1, post + leftPreSize,
                                           preSize - leftPreSize - 1);
    }
    return root;
}

int main() {
    int pre[] = {2, 1, 3};
    int post[] = {3, 1, 2};
    struct TreeNode *n = constructFromPrePost(pre, 3, post, 3);
    return 0;
}