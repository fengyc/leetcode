#include <string.h>

int minDeletionSize(char **A, int ASize) {
    int k = 0;

    if (A) {
        if (ASize) {
            if (A[0]) {
                int rows = ASize;
                int cols = strlen(A[0]);
                for (int i = 0; i < cols; i++) {
                    for (int j = 0; j < rows - 1; j++) {
                        if (A[j][i] > A[j + 1][i]) {
                            k++;
                            break;
                        }
                    }
                }
            }
        }
    }

    return k;
}

int main() {
    char *a[] = {
            "cba", "daf", "ghi"
    };
    int r = minDeletionSize(a, 3);

    return 0;
}