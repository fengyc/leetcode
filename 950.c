#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

struct N {
    int idx;
    struct N *next;
};

int *deckRevealedIncreasing(int *deck, int deckSize, int *returnSize) {
    qsort(deck, deckSize, sizeof(int), cmp);

    struct N *n = malloc(sizeof(struct N) * deckSize);
    for (int i = 0; i < deckSize; i++) {
        n[i].idx = i;
        if (i < deckSize - 1) {
            n[i].next = &n[i + 1];
        }
    }
    n[deckSize - 1].next = NULL;
    struct N *ptail = &n[deckSize - 1];

    struct N *q = n;
    struct N *p = q->next;
    struct N *qtail = n;
    qtail->next = NULL;

    while (p) {
        if (!p->next) {
            qtail->next = p;
            break;
        }

        ptail->next = p;
        ptail = ptail->next;

        qtail->next = p->next;
        qtail = qtail->next;

        p = qtail->next;
        ptail->next = NULL;
        qtail->next = NULL;
    }

    int *r = malloc(sizeof(int) * deckSize);
    p = q;
    for (int i = 0; i < deckSize; i++) {
        r[p->idx] = deck[i];
        p = p->next;
    }
    *returnSize = deckSize;

    free(n);

    return r;
}

int main() {
    int a[] = {
            17, 13, 11, 2, 3, 5, 7
    };

    int s;
    int *r = deckRevealedIncreasing(a, 7, &s);

    for (int i=0; i< s; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}

