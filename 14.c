#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize <= 0) {
        char *s = malloc(sizeof(char) *1);
        s[0] = 0;
        return s;
    }
    int len = 0;
    int minSlen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int slen = strlen(strs[i]);
        minSlen = minSlen < slen ? minSlen : slen;
    }
    for (int i = 0; i < minSlen; i++) {
        int flag = 1;
        for (int j = 1; j < strsSize; j++) {
            if (strs[0][i] != strs[j][i]) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            break;
        }
        len++;
    }
    char *s = malloc(len+1);
    memcpy(s, strs[0], len);
    s[len] = 0;
    return s;
}

int main() {
    char **ss = malloc(sizeof(char *) * 3);
    ss[0] = "Hello";
    ss[1] = "Helbbbbb";
    ss[2] = "Helk";
    char *s = longestCommonPrefix(ss, 3);
    printf("%s\n", s);
}
