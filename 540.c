int singleNonDuplicate(int *nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (r - l > 1) {
        int k = (l + r) / 2;
        if (k > l && nums[k] == nums[k - 1]) {
            k++;
        }
        if ((k - l) & 0x01) {
            r = k;
        } else {
            l = k;
        }
    }
    if (l == 0 || nums[l] != nums[l - 1]) {
        return nums[l];
    }
    return nums[r];
}

int sol2(int *nums, int numsSize) {
    int r = 0;
    for (int i = 0; i < numsSize; i++) {
        r ^= nums[i];
    }
    return r;
}

int sol3(int *nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i += 2) {
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}

int main() {

    int nums[] = {
            1, 1, 2, 2, 3, 4, 4, 5, 5
    };

    int r = singleNonDuplicate(nums, sizeof(nums) / sizeof(int));

    r = sol2(nums, sizeof(nums) / sizeof(int));

    return 0;
}