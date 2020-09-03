#include <stdlib.h>

int distributeCandies(int *candies, int candiesSize) {
    char *bits = calloc(200000 / 8 + 1, sizeof(char));
    for (int i = 0; i < candiesSize; i++) {
        int offset = candies[i] + 100000;
        bits[offset / 8] |= (1 << (offset % 8));
    }
    int count = 0;
    for (int i = 0; i <= 200000; i++) {
        if (bits[i / 8] & (1 << (i % 8))) {
            count++;
        }
    }
    if (count < candiesSize / 2) {
        return count;
    }
    return candiesSize / 2;
}

int main() {
    int c[] = {
            100000, 0, 100000, 0, 100000, 0, 100000, 0, 100000, 0, 100000, 0
    };

    int k = distributeCandies(c, 6);

    return 0;
}
