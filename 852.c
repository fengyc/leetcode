int peakIndexInMountainArray(int *A, int ASize) {
    int *p = A;
    while (*p < *(p+1)) {
        p++;
    }
    return p-A;
}

int main() {
    int a[] = {
            0, 2, 1, 0
    };

    int r = peakIndexInMountainArray(a, 4);

    return 0;
}