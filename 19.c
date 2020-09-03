/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    int len = 0;
    struct ListNode *p = head;
    while(p) {
        len ++;
        p = p->next;
    }

    int k = len - n;

    if (k==0) {
        return head->next;
    }

    p = head;
    for (int i=1;i<k;i++) {
        p = p->next;
    }
    p->next = p->next->next;

    return head;
}

