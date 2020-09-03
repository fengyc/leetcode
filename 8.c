#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char *str) {
    int negative = 0;
    long n = 0;

    while (*str == ' ') {
        str++;
    }

    if (*str == 0 || (*str != '-' && *str != '+' && *str < '0' && *str > '9')) {
        return n;
    }

    if (*str == '-') {
        negative = 1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str != 0 && (*str >= '0' && *str <= '9')) {
        if (negative) {
            n = n * 10 - (*str - '0');
            if (n < INT_MIN) {
                return INT_MIN;
            }
        } else {
            n = n * 10 + (*str - '0');
            if (n > INT_MAX) {
                return INT_MAX;
            }
        }
        str++;
    }

    return n;
}

int main() {
    printf("%d\n", myAtoi("-91283472332"));
    return 0;
}