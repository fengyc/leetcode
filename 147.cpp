#include <stdlib.h>

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode *h = new ListNode(head->val);
        ListNode *p = head->next;
        while(p) {
            ListNode *tmp = new ListNode(p->val);
            if (p->val < h->val) {
                tmp->next = h;
                h = tmp;
            } else {
                ListNode *hp = h;
                while (hp->next && hp->next->val < tmp->val) {
                    hp = hp->next;
                }
                tmp->next = hp->next;
                hp->next = tmp;
            }
            p = p->next;
        }
        return h;
    }
};

int main() {
    Solution s;

    // -1->5->3->4->0
    ListNode n1(-1);
    ListNode n2(5);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(0);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    auto r = s.insertionSortList(&n1);

    return 0;
}