#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head;
    struct ListNode *p;

    if (!l1 && !l2) {
        return NULL;
    }
    if (!l2) {
        return l1;
    }
    if (!l1) {
        return l2;
    }

    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    p = head;

    while(l1 && l2) {
        if (l1->val <= l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    if (l1) {
        p->next = l1;
    }
    if (l2) {
        p->next = l2;
    }

    return head;
}

int main() {
    return 0;
}