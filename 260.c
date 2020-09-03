
#include <stdlib.h>

int *singleNumber(int *nums, int numsSize, int *returnSize) {
    *returnSize = 2;
    int *r = calloc(2, sizeof(int));
    int xor = 0;
    for (int i = 0; i < numsSize; i++) {
        xor ^= nums[i];
    }
    // 得到 x^y，以 xor 结果其中任意一个为1 bit 为区分两个数，取反 +1 得到最后一个为1的 bit
    // 这样把数分成了两组
    xor &= (~xor + 1);
    for (int i=0;i<numsSize;i++) {
        if (nums[i] & xor) {
            r[0] ^= nums[i];        // 出现2次的数经 xor 后为0
        } else {
            r[1] ^= nums[i];
        }
    }
    return r;
}