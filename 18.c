#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 0;
    if (numsSize < 4) {
        return NULL;
    }

    int **arr = malloc(sizeof(int *) * 10000);

    for (int i = 0; i < numsSize - 3; i++) {
        int sumi = nums[i];
        for (int j = i + 1; j < numsSize - 2; j++) {
            int sumj = nums[j] + sumi;
            for (int k = j + 1; k < numsSize - 1; k++) {
                int sumk = nums[k] + sumj;
                for (int l = k + 1; l < numsSize; l++) {
                    int suml = nums[l] + sumk;
                    if (suml == target) {
                        arr[*returnSize] = malloc(sizeof(int) * 4);
                        arr[*returnSize][0] = nums[i];
                        arr[*returnSize][1] = nums[j];
                        arr[*returnSize][2] = nums[k];
                        arr[*returnSize][3] = nums[l];
                        *returnSize = *returnSize + 1;
                    }
                }
            }
        }
    }

    return arr;
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int s = 0;
    int **arr = fourSum(nums, 6, 0, &s);
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

