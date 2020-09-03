#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *p = head;
    head = head->next;
    p->next = head->next;
    head->next = p;

    while (p->next && p->next->next) {
        struct ListNode *next = p->next;
        p->next = next->next;
        next->next = p->next->next;
        p->next->next = next;
        p = next;
    }

    return head;
}

int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 0;
    struct ListNode *p = head;

    for (int i = 1; i < 9; i++) {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));
        tmp->val = i;
        tmp->next = NULL;
        p->next = tmp;
        p = tmp;
    }

    p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = swapPairs(head);
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}