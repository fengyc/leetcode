#include <stdio.h>

int romanToInt(char *s) {
    int n = 0;
    if (*s == 0) {
        return 0;
    }
    switch (*s) {
        case 'M':
            n = 1000;
            break;
        case 'D':
            n = 500;
            break;
        case 'C':
            n = 100;
            if (*(s+1) == 'M' || *(s+1) == 'D') {
                n = -100;
            }
            break;
        case 'L':
            n = 50;
            break;
        case 'X':
            n = 10;
            if (*(s+1) == 'C' || *(s+1) == 'L') {
                n = -10;
            }
            break;
        case 'V':
            n = 5;
            break;
        case 'I':
            n = 1;
            if (*(s+1) == 'X' || *(s+1) == 'V') {
                n = -1;
            }
    }
    return n + romanToInt(++s);
}

int main() {
    int n = romanToInt("MCMXCIV");
    printf("%d\n", n);
}