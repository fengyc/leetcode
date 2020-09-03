#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<vector<TreeNode *>> cache = {{}, {new TreeNode(0)}};

    vector<TreeNode *> allPossibleFBT(int N) {
        vector<TreeNode *> v;

        if (cache.size() > N) {
            return cache[N];
        }

        for (int i = 0; i < N; i++) {
            int left = i;               // left node number
            int right = N - i - 1;      // right node number
            vector<TreeNode *> ltree = allPossibleFBT(left);
            vector<TreeNode *> rtree = allPossibleFBT(right);
            for (auto ln : ltree) {
                for (auto rn : rtree) {
                    TreeNode *n = new TreeNode(0);
                    n->left = ln;
                    n->right = rn;
                    v.push_back(n);
                }
            }
        }

        cache.push_back(v);
        return v;
    }
};


int main() {
    Solution s;

    cout << sizeof(vector<TreeNode *>) << endl;

    auto t7 = s.allPossibleFBT(7);

    return 0;
}
