#include <stdlib.h>

int cmp(const void *x, const void *y) {
    return (*(int *)x) - (*(int *)y);
}

int* sortedSquares(int* A, int ASize, int* returnSize) {
    if (returnSize) {
        *returnSize = ASize;
    }
    if (ASize == 0) {
        return A;
    }

    for (int i=0;i<ASize; i++) {
        A[i] = A[i] * A[i];
    }

    qsort(A, ASize, sizeof(int), cmp);

    return A;
}

int main() {

    int a[] = {
            -7,-3,2,3,11
    };

    int *b = sortedSquares(a, 5, NULL);

    return 0;
}