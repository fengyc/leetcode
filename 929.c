#include <stdlib.h>

int numUniqueEmails(char **emails, int emailsSize) {
    for (int i = 0; i < emailsSize - 1; i++) {
        char *email = emails[i];
        if (email) {
            for (int j = i+1; j < emailsSize; j++) {
                char *p1 = email;
                char *p2 = emails[j];
                int local1 = 1;
                int local2 = 1;

                if (emails[j] == NULL) {
                    continue;
                }

                while (*p1 && *p2) {
                    if (*p1 == '@') {
                        local1 = 0;
                        p1++;
                    }
                    if (*p2 == '@') {
                        local2 = 0;
                        p2++;
                    }

                    while (*p1 == '.' && local1) {
                        p1++;
                    }
                    while (*p2 == '.' && local2) {
                        p2++;
                    }

                    if (*p1 == '+' && local1) {
                        while (*p1) {
                            p1++;
                            if (*p1 == '@') {
                                p1++;
                                local1 = 0;
                                break;
                            }
                        }
                    }
                    if (*p2 == '+' && local2) {
                        while (*p2) {
                            p2++;
                            if (*p2 == '@') {
                                p2++;
                                local2 = 0;
                                break;
                            }
                        }
                    }

                    if (*p1 != *p2) {
                        break;
                    }
                    p1++;
                    p2++;
                }
                if (*p1 || *p2) {
                    continue;
                }
                emails[j] = NULL;   // same
            }
        }
    }
    int count = 0;
    for (int i = 0; i < emailsSize; i++) {
        if (emails[i] && emails[i][0]) {
            count++;
        }
    }
    return count;
}

int main() {
    char *arr[] = {
            "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"
    };
    int k = numUniqueEmails(arr, 3);
    return 0;
}