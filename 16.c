#include <math.h>
#include <limits.h>
#include <stdio.h>

int threeSumClosest(int *nums, int numsSize, int target) {
    int min_diff = INT_MAX;
    int min_sum = 0;
    for (int *a = nums; a < nums + numsSize - 2; a++) {
        for (int *b = a + 1; b < nums + numsSize - 1; b++) {
            int s = *a + *b;
            for (int *c = b + 1; c < nums + numsSize; c++) {
                int sum = s + *c;
                int diff = target - sum;
                diff = diff < 0 ? -diff : diff;
                if (diff < min_diff) {
                    min_diff = diff;
                    min_sum = sum;
                    if (diff == 0) {
                        return min_sum;
                    }
                }
            }
        }
    }
    return min_sum;
}

int main() {
    int arr[] = {1,1,1,0};
    int s = threeSumClosest(arr, 4, -100);
    printf("%d\n", s);
}