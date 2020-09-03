#include <stdlib.h>

int *sortArrayByParity(int *A, int ASize, int *returnSize) {
    int *B = malloc(sizeof(int) * ASize);
    if (returnSize) {
        *returnSize = ASize;
    }

    int l = 0;
    int r = ASize - 1;
    for (int i = 0; i < ASize; i++) {
        if ((A[i] & 0x01) == 0) {
            B[l++] = A[i];
        } else {
            B[r--] = A[i];
        }
    }

    return B;
}

int main() {
    int a[] = {
            0, 2
    };
    int *b = sortArrayByParity(a, 2, NULL);
    return 0;
}