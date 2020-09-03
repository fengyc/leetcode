int removeElement(int *nums, int numsSize, int val) {
    if (numsSize <= 0) {
        return 0;
    }

    int p = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val ) {
            nums[p++] = nums[i];
        }
    }

    if (nums[0] == val) {
        return 0;
    }

    return p;
}


int main() {
    int arr[10] = {7, 1, 2, 3, 5, 5, 7, 7, 8, 9};
    int n = removeElement(arr, 10, 7);
    return 0;
}