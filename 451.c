#include <stdlib.h>
#include <string.h>

int f[256] = {0};

int cmp(const void *a, const void *b) {
    char ca = *(char *) a;
    char cb = *(char *) b;
    int fa = f[ca];
    int fb = f[cb];
    if (fa != fb) {
        return fb - fa;
    }
    return ca - cb;
}

char *frequencySort(char *s) {
    memset(f, 0, sizeof(f));
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        f[s[i]] += 1;
    }
    qsort(s, len, sizeof(char), cmp);
    return s;
}

int main() {

    char *s = "tree";

    qsort(s, strlen(s), sizeof(char), cmp);

    frequencySort(s);

    return 0;
}