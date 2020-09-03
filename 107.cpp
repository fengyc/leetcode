#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> r;
        deque<TreeNode *> dq;

        if (root) {
            dq.push_back(root);
        }

        while (dq.size()) {
            int size = dq.size();
            r.emplace_back();
            for (int i = 0; i < size; i++) {
                int val = dq.front()->val;
                TreeNode *left = dq.front()->left;
                TreeNode *right = dq.front()->right;
                dq.pop_front();
                
                if (left) {
                    dq.push_back(left);
                }
                if (right) {
                    dq.push_back(right);
                }
                
                r.back().push_back(val);
            }
        }
        
        reverse(r.begin(), r.end());
        return r;
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.right = &n5;
    n5.left = &n6;
    
    Solution s;
    auto r = s.levelOrderBottom(&n1);
    
    return 0;
}