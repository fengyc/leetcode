#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

char *convert(char *s, int numRows) {
    int len = strlen(s);
    if (numRows < 2 || numRows >= len || len <= 2) {
        return s;
    }
    int part_size = (numRows << 1) - 2;
    int remains = len % part_size;
    int parts = len / part_size;
    if (remains > 0) {
        parts += 1;
    }

    char *buf = (char *) malloc(len + 1);
    buf[len] = 0;

    int X = parts << 1;
    int Y = numRows;
    int i = 0;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            int part = x >> 1;
            int offset = 0;
            int start = part * part_size;
            if ((x & 0x01) == 0) {
                offset = y;
            } else {
                if (y == 0 || y == Y - 1) {
                    continue;
                }
                offset = (Y << 1) - 2 - y;
            }
            if( start + offset >= len) {
                continue;
            }
            buf[i] = s[start + offset];
            i++;
            if (i >= len) {
                return buf;
            }
        }
    }
    return buf;
}

int main() {
    char *s = "PAYPALISHIRING";
    int numRows = 4;
    char *s2 = convert(s, numRows);
    printf("%s", s2);
    return 0;
}
