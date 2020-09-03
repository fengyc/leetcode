#include <string.h>
#include <stdlib.h>

int countSubstrings(char *s) {
    int len = strlen(s);
    char **dp = malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++) {
        dp[i] = calloc(len, sizeof(char));
    }
    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        for (int j = i; j < len; j++) {
            if (i == j) {
                dp[i][j] = 1;
                count++;
            } else if (j == i + 1) {
                if (s[i] == s[j]) {
                    dp[i][j] = 1;
                    count++;
                }
            } else {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {

    char *s = "ababa";

    int r = countSubstrings(s);

    return 0;
}