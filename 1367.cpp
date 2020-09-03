/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (check(head, root))
        {
            return true;
        }
        if (root)
        {
            return isSubPath(head, root->left) || isSubPath(head, root->right);
        }

        return false;
    }

    bool check(ListNode *p, TreeNode *root)
    {
        if (p == nullptr)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }

        if (p->val == root->val)
        {
            p = p->next;
        }
        else
        {
            return false;
        }

        return check(p, root->left) || check(p, root->right);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    auto l1 = new ListNode(1);
    auto l10 = new ListNode(10);
    l1->next = l10;

    auto t1 = new TreeNode(1);
    auto t1_1 = new TreeNode(1);
    auto t10 = new TreeNode(10);
    auto t1_2 = new TreeNode(1);
    auto t9 = new TreeNode(9);

    t1->right = t1_1;
    t1_1->left = t10;
    t10->left = t1_2;
    t1_2->left = t9;

    auto result = s.isSubPath(l1, t1);

    return 0;
}
