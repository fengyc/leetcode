#include <queue>

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

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
        while(root) {
            if (root->left) {
                q.push(root->left);
                if (root->right) {
                    q.push(root->right);
                    q.pop();
                    root = q.front();
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }
    }

    int insert(int v) {
        TreeNode *n = q.front();
        if (!n->left) {
            n->left = new TreeNode(v);
            q.push(n->left);
        } else {
            n->right = new TreeNode(v);
            q.push(n->right);
            q.pop();
        }
        return n->val;
    }

    TreeNode* get_root() {
        return this->root;
    }

private:
    TreeNode *root;
    queue<TreeNode *> q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

int main() {

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);

    n1->left = n2;
    n2->left = n4;
    n2->right = n5;

    n1->right = n3;
    n3->left = n6;

    CBTInserter *c = new CBTInserter(n1);
    int r = c->insert(7);
    r = c->insert(8);

    return 0;
}