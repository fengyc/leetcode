#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    int len = strlen(s);
    if ((len & 0x01) != 0) {
        return false;
    }

    int slen = len >> 1;
    char *stack = malloc(slen);
    int top = -1;
    while (*s) {
        if (top >= 0) {
            if ((stack[top] == '(' && *s == ')') || (stack[top] == '[' && *s == ']') ||
                (stack[top] == '{' && *s == '}')) {
                top -= 1;
                s++;
                continue;
            }
            if (top == slen - 1) {
                return false;
            }
        }
        stack[++top] = *s;
        s++;
    }
    if (top != -1) {
        return false;
    }
    return true;
}

bool isValid2(char *s) {

}

int main() {
    char *s = "([)]";
    bool r = isValid(s);

    s = "()[]{}";
    r = isValid(s);

    return 0;
}