
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto head = l1;
        auto tail = l1;
        while (l1 && l2) {
            l1->val += l2->val;
            tail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2) {
            if (tail) {
                tail->next = l2;
            } else {
                head = l2;
            }
        }

        auto p = head;
        while(p) {
            if (p->val >= 10) {
                if (p->next) {
                    p->next->val += 1;
                } else {
                    p->next = new ListNode(1);
                }
                p->val -= 10;
            }
            p = p->next;
        }

        return head;
    }
};

int main() {
    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode(5);

    Solution s;
    auto r = s.addTwoNumbers(l1, l2);

    return 0;
}