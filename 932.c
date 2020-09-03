#include <stdlib.h>
#include <stdio.h>

void fill(int *pa, int *pb, int l, int r) {
    if (pa > pb) {
        return;
    }
    *pa = l;
    *pb = r;
    l -= 1;
    r += 1;
    pa++;
    pb--;
    fill(pa, pb, l, r);
}

int *beautifulArray(int N, int *returnSize) {
    int *arr = calloc(N, sizeof(int));
    int *pa, *pb;
    int l, r;

    if (N % 2 == 0) {
        l = N / 2;
        r = l + 1;
        pa = arr;
        pb = &arr[N - 1];
    } else {
        l = (N + 1) / 2;
        arr[0] = l;
        l = l - 1;
        r = l + 2;
        pa = &arr[1];
        pb = &arr[N - 1];
    }

    while (pa < pb) {
        *pa = l;
        *pb = r;
        l--;
        r++;
        pa++;
        pb--;
    }

    *returnSize = N;
    return arr;
}

int main() {
    int s;
    int *p = beautifulArray(7, &s);
    for (int i = 0; i < s; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}