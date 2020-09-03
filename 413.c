#include <stdlib.h>

int numberOfArithmeticSlices(int *A, int ASize) {
    char **dp = malloc(sizeof(char *) * ASize);
    for (int i = 0; i < ASize; i++) {
        dp[i] = calloc(ASize, sizeof(char));
    }
    int count = 0;
    for (int i = 0; i < ASize - 2; i++) {
        for (int j = i + 2; j < ASize; j++) {
            if (A[j] - A[j - 1] == A[j - 1] - A[j - 2]) {
                if (j == i + 2) {
                    if (A[j] - A[j - 1] == A[j - 1] - A[i]) {
                        dp[i][j] = 1;
                        count++;
                    }
                } else if (dp[i][j - 1]) {
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {

    int a[] = {
            1, 2, 3, 4, 6, 8
    };

    int r = numberOfArithmeticSlices(a, sizeof(a) / sizeof(int));

    return 0;
}