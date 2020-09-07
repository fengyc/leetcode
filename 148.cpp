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
 
// insert sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *r = nullptr;

        while (head) {
            if (!r || r->val > head->val) {
                auto tmp = r;
                r = head;
                head = head->next;
                r->next = tmp;
            } else {
                auto *p0 = r;
                auto p1 = r->next;
                while(p1 && p1->val < head->val) {
                    p0 = p1;
                    p1 = p1->next;
                }
                p0->next = head;
                head = head->next;
                p0->next->next = p1;
            }
        }

        return r;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    auto l_1 = new ListNode(-1);
    auto l_3 = new ListNode(-3);
    auto l_4 = new ListNode(-4);
    auto l0 = new ListNode(0);
    auto l5 = new ListNode(5);
    auto l3 = new ListNode(3);

    l_1->next = l_3;
    l_3->next = l_4;
    l_4->next = l0;
    l0->next= l5;
    l5->next = l3;

    auto r = s.sortList(l_1);

    return 0;
}
