#include <vector>

using namespace std;

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
    TreeNode *sortedListToBST(ListNode *head)
    {
        int vec[20001] = {0};
        int count = 0;
        while (head)
        {
            vec[count++] = head->val;
            head = head->next;
        }
        return createTree(vec, 0, count - 1);
    }

    TreeNode *createTree(int *vec, int from, int to)
    {
        if (from > to)
        {
            return nullptr;
        }
        auto mid = (from + to) / 2;
        auto root = new TreeNode(vec[mid]);
        root->left = createTree(vec, from, mid - 1);
        root->right = createTree(vec, mid + 1, to);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    //  [-10,-3,0,5,9]
    auto l_10 = new ListNode(-10);
    auto l_3 = new ListNode(-3);
    auto l0 = new ListNode(0);
    auto l5 = new ListNode(5);
    auto l9 = new ListNode(9);

    l_10->next = l_3;
    l_3->next = l0;
    l0->next = l5;
    l5->next = l9;
    l9->next = nullptr;

    auto r = s.sortedListToBST(l_10);

    return 0;
}
