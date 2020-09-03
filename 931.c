#include <stdlib.h>
#include <string.h>

int minFallingPathSum(int **A, int ARowSize, int *AColSizes) {
    int **dp = malloc(sizeof(int *) * 2);
    dp[0] = malloc(sizeof(int) * ARowSize);
    dp[1] = malloc(sizeof(int) * ARowSize);
    memcpy(dp[0], A[0], sizeof(int) * ARowSize);
    int old = 0;
    int new = 1;
    for (int i = 1; i < ARowSize; i++) {
        for (int j = 0; j < ARowSize; j++) {
            int min = dp[old][j];
            if (j > 0) {
                min = min > dp[old][j - 1] ? dp[old][j - 1] : min;
            }
            if (j < ARowSize - 1) {
                min = min > dp[old][j + 1] ? dp[old][j + 1] : min;
            }
            dp[new][j] = A[i][j] + min;
        }
        old ^= 1;
        new ^= 1;
    }
    int min = dp[old][0];
    for (int i = 0; i < ARowSize; i++) {
        min = min > dp[old][i] ? dp[old][i] : min;
    }
    return min;
}

int main() {
    int **a = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++) {
        a[i] = malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++) {
            a[i][j] = i * 3 + j + 1;
        }
    }

    int colsizes[] = {3, 3, 3};

    int r = minFallingPathSum(a, 3, colsizes);

    return 0;

}