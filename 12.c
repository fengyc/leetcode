#include <stdlib.h>
#include <stdio.h>

char *intToRoman(int num) {
    char *s = (char *) malloc(1000);
    int len = 0;
    int remain = num;
    while (remain) {
        if (remain >= 900) {
            if (remain >= 1000) {
                s[len++] = 'M';
                remain -= 1000;
            } else {
                s[len++] = 'C';
                s[len++] = 'M';
                remain -= 900;
            }
            continue;
        }
        if (remain >= 400) {
            if (remain >= 500) {
                s[len++] = 'D';
                remain -= 500;
            } else {
                s[len++] = 'C';
                s[len++] = 'D';
                remain -= 400;
            }
            continue;
        }
        if (remain >= 90) {
            if (remain >= 100) {
                s[len++] = 'C';
                remain -= 100;
            } else {
                s[len++] = 'X';
                s[len++] = 'C';
                remain -= 90;
            }
            continue;
        }
        if (remain >= 40) {
            if (remain >= 50) {
                s[len++] = 'L';
                remain -= 50;
            } else {
                s[len++] = 'X';
                s[len++] = 'L';
                remain -= 40;
            }
            continue;
        }
        if (remain >= 9) {
            if (remain >= 10) {
                s[len++] = 'X';
                remain -= 10;
            } else {
                s[len++] = 'I';
                s[len++] = 'X';
                remain -= 9;
            }
            continue;
        }
        if (remain >= 4) {
            if (remain >= 5) {
                s[len++] = 'V';
                remain -= 5;
            } else {
                s[len++] = 'I';
                s[len++] = 'V';
                remain -= 4;
            }
            continue;
        } else {
            s[len++] = 'I';
            remain -= 1;
        }
    }
    s[len] = 0;
    return s;
}

int main() {
    char *s = intToRoman(1994);
    printf("%s\n", s);
}