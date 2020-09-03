#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverse(struct ListNode *head, int k, struct ListNode **newTail) {
    if (k > 1 && head && head->next) {
        struct ListNode *newHead = reverse(head->next, k - 1, newTail);
        head->next = (*newTail)->next;
        (*newTail)->next = head;
        *newTail = (*newTail)->next;
        return newHead;
    }
    *newTail = head;
    return head;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k) {

    if (k <= 1 || head == NULL) {
        return head;
    }

    struct ListNode **stack = malloc(sizeof(struct ListNode *) * k);
    int size = 0;

    struct ListNode *p = head;
    head = NULL;
    struct ListNode *tail = NULL;

    while (p) {
        stack[size++] = p;
        p = p->next;
        if (size == k) {
            stack[0]->next = stack[size - 1]->next;
            for (int i = size - 1; i > 0; i--) {
                stack[i]->next = stack[i - 1];
            }
            if (head == NULL) {
                head = stack[size - 1];
            }
            if (tail) {
                tail->next = stack[size - 1];
            }
            tail = stack[0];
            size = 0;
        }
    }

    if (head == NULL) {
        head = stack[0];
    }

    free(stack);

    return head;
}

int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 0;
    struct ListNode *p = head;

    for (int i = 1; i < 5; i++) {
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

    p = reverseKGroup(head, 6);
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}