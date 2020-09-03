#import <cstdlib>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }

        auto pa = headA;
        auto pb = headB;

        auto a_null = false;
        auto b_null = false;
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;

            if ((!pa || !pb) && (a_null && b_null)) {
                break;
            }

            if (!pa) {
                pa = headB;
                a_null = true;
            }
            if (!pb) {
                pb = headA;
                b_null = true;
            }
        }

        return pa == pb ? pa : nullptr;
    }
};

int main() {
    /* [4,1,8,4,5]
        [5,0,1,8,4,5]*/

    auto n0 = ListNode(0);
    auto n1 = ListNode(1);
    auto n4 = ListNode(4);
    auto n41 = ListNode(4);
    auto n5 = ListNode(5);
    auto n51 = ListNode(5);
    auto n8 = ListNode(8);

    n1.next = &n8;
    n8.next = &n4;
    n4.next = &n5;

    n41.next = &n1;

    n51.next = &n0;
    n0.next = &n1;

    Solution s;
    auto p = s.getIntersectionNode(&n41, &n51);

    return 0;
}