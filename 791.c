#include <stdlib.h>
#include <string.h>

int order[26] = {0};

int cmp(const void *a, const void *b) {
    int ordera = order[*(char *)a];
    int orderb = order[*(char *)b];
    if (ordera && orderb) {
        return ordera - orderb;
    }
    if (ordera) {
        return -1;
    }
    if (orderb) {
        return 1;
    }
    return *(char *)a - *(char *)b;
}

char* customSortString(char* S, char* T) {
    int i = 0;
    while (*S) {
        order[*S - 'a'] = ++i;
        S++;
    }

    qsort(T, strlen(T), sizeof(char), cmp);

    return T;
}