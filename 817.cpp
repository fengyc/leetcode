#include <vector>
#include <set>

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

class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &G)
    {
        set<int> s;
        for (auto g = G.begin(); g != G.end(); g++)
        {
            s.insert(*g);
        }

        auto count = 0;
        while (head != nullptr)
        {
            while (head != nullptr && s.find(head->val) == s.end())
            {
                head = head->next;
            }

            auto tail = head;
            while (tail != nullptr && tail->next != nullptr && s.find(tail->next->val) != s.end())
            {
                tail = tail->next;
            }

            if (head != nullptr)
            {
                count += 1;
                head = tail->next;
            }
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> G = {0, 3, 1, 4};

    auto n0 = new ListNode(0);
    auto n1 = new ListNode(1);
    auto n2 = new ListNode(2);
    auto n3 = new ListNode(3);
    auto n4 = new ListNode(4);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    auto r = s.numComponents(n0, G);

    return 0;
}
