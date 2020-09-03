#include <stdbool.h>
#include <stdlib.h>

bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize) {
    int *stack = malloc(pushedSize * sizeof(int));
    int top = -1;
    int i = 0, j = 0;
    while (i != pushedSize && j != poppedSize) {
        if (top >= 0 && stack[top] == popped[j]) {
            top--;
            j++;
        } else {
            stack[++top] = pushed[i++];
        }
    }
    while (j < poppedSize && stack[top] == popped[j]) {
        top--;
        j++;
    }
    return top == -1;
}

int main() {
    int p1[] = {1, 2, 3, 4, 5};
    int p2[] = {4, 5, 3, 2, 1};

    bool r = validateStackSequences(p1, sizeof(p1) / sizeof(int), p2, sizeof(p2) / sizeof(int));

    return 0;
}