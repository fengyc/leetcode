int repeatedNTimes(int *A, int ASize) {
    int i = 0;
    for (i = 0; i < ASize - 2; i++) {
        if (A[i] == A[i+1] || A[i] == A[i+2]) {
            return A[i];
        }
    }
    return A[i+1];
}

int main() {
    int a[] = {
            1, 2, 3, 3
    };
    int r = repeatedNTimes(a, 4);
    return 0;
}