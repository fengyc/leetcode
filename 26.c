int removeDuplicates(int *nums, int numsSize) {
    int p = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != nums[p]) {
            nums[++p] = nums[i];
        }
    }
    return p + 1;
}

int main() {
    int arr[10] = {0, 1, 2, 3, 5, 5, 7, 7, 8, 9};
    int n = removeDuplicates(arr, 10);
    return 0;
}