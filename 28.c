
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int comp(char *s1, char *s2, int len) {
    for (int i=0; i<len; i++) {
if (s1[i] != s2[i]) {
return -1;
}
}
return 1;
}

int strStr(char* haystack, char* needle) {
    if (haystack == NULL || needle == NULL) {
        return -1;
    }

    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    if (nlen > hlen) {
        return -1;
    }

    char *p = haystack;
    char *c = needle;
    int k = hlen - nlen + 1;

    while (p && k--) {
        if (comp(p, needle, nlen) > 0) {
            return p - haystack;
        }
        p++;
    }
    return -1;
}

int main() {
    char *s1 = "abb";
    char *s2 = "abaaa";

    int n = strStr(s1, s2);

    return 0;
}