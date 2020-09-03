#include <stdio.h>

int *sortArrayByParityII(int *A, int ASize, int *returnSize) {
    int l = 0;
    int r = ASize - 1;
    while (l < ASize) {
        if (A[l] & 0x01) {
            while (A[r] & 0x01) {
                r -= 2;
            }
            int tmp = A[l];
            A[l] = A[r];
            A[r] = tmp;
        }
        l += 2;
    }
    *returnSize = ASize;
    return A;
}

int main() {
    int a[] = {4,2,5,7};

    int bsize;
    int *b = sortArrayByParityII(a, 4, &bsize);

    for (int i =0;i<bsize; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}
