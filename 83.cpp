/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }

        auto p0 = head;
        auto p1 = head->next;
        while (p1) {
            if (p1->val == p0->val) {
                p0->next = p1->next;
            } else {
                p0 = p1;
            }
            p1 = p0->next;
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    auto l1 = new ListNode(1);
    auto l1_2 = new ListNode(1);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(3);
    auto l3_2 = new ListNode(3);

    l1->next = l1_2;
    l1_2->next = l2;
    l2->next = l3;
    l3->next = l3_2;

    auto r = s.deleteDuplicates(l1);

    return 0;
}
