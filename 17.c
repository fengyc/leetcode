#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void comb(char *digits, char **buf, int offset, int *lines) {
    char *table[] = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };

    if (*digits == 0) {
        buf[0][offset] = 0;
        *lines = 1;
        return;
    }

    char *chars = table[*digits - '2'];
    size_t len = strlen(chars);

    comb(digits+1, buf, offset + 1, lines);


    for (int i = 0; i < len; i++) {
        int start = i * (*lines);
        for (int j = 0; j < (*lines); j++) {
            buf[j + start][offset] = chars[i];
            if (start != 0) {
                memcpy(&buf[j+start][offset+1], &buf[j][offset+1], strlen(digits));
            }
        }
    }
    *lines = len * (*lines);
}

char **letterCombinations(char *digits, int *returnSize) {
    char *table[] = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };

    size_t len = strlen(digits);

    if (len > 0) {
        *returnSize = 1;
    } else {
        *returnSize = 0;
        return NULL;
    }

    char *p = digits;
    while (*p) {
        *returnSize = *returnSize * strlen(table[*p - '2']);
        p++;
    }

    char **arr = malloc(sizeof(char *) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        arr[i] = malloc(len + 1);
    }

    int tmp = 0;
    comb(digits, arr, 0, &tmp);

    return arr;
}

int main() {
    int len = 0;
    char *digits = "23";
    char **s = letterCombinations(digits, &len);
    for (int i = 0; i< len; i++) {
        printf("%s\n", s[i]);
    }
}