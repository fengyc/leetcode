#include <vector>

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

    vector<int> subSum(TreeNode *root, int *sum) {
        vector<int> r;
        if (root == NULL) {
            *sum = 0;
            return r;
        }
        int ls, rs;
        vector<int> lr = subSum(root->left, &ls);
        for (auto i : lr) {
            r.push_back(i);
        }
        vector<int> rr = subSum(root->right, &rs);
        for (auto i : rr) {
            r.push_back(i);
        }
        *sum = ls + rs + root->val;
        r.push_back(*sum);
        return r;
    }

    static bool cmp(int &a, int &b) {
        return a <= b;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        int sum;
        vector<int> r = subSum(root, &sum);
        sort(r.begin(), r.end(), cmp);

    }
};