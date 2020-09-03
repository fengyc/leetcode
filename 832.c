#include <stdlib.h>

int **flipAndInvertImage(int **A, int ARowSize, int *AColSizes, int **columnSizes, int *returnSize) {
    int **B = malloc(sizeof(int *) * ARowSize);
    *columnSizes = malloc(sizeof(int) * ARowSize);

    for (int i = 0; i < ARowSize; i++) {
        int colSize = AColSizes[i];
        B[i] = malloc(sizeof(int) * colSize);
        for (int j = 0; j < colSize; j++) {
            B[i][j] = A[i][colSize - j - 1];
            B[i][j] = B[i][j] ? 0 : 1;
        }
        (*columnSizes)[i] = colSize;
    }
    if (returnSize) {
        *returnSize = ARowSize;
    }
    return B;
}

int main() {
    int *a[] = {
            {1, 1, 0, 0},
            {1, 0, 0, 1},
            {0, 1, 1, 1},
            {1, 0, 1, 0}
    };

}