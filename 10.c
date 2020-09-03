#include <stdlib.h>
#include <string.h>

struct ReNode {
    char c;     // char
    char num;   // num of char, 1/n
    int last;   // last match index
};

int isMatch(char *s, char *p) {
    int slen = strlen(s);

    // pre process
    struct ReNode *re = (struct ReNode *) malloc(strlen(p));
    char *cur = p;
    int len = 0;
    while (*cur) {
        re[len].c = *cur;
        if (*(cur + 1) == '*') {
            re[len].num = 'n';
            cur++;
        } else {
            re[len].num = '1';
        }
        re[len].last = 0;

        cur++;
        len++;
    }

    // matching, max
    int i = 0;
    int j = 0;
    while (1) {
        if (re[i].c == '.' || re[i].c == s[j]) {
            re[i].last = j;
            j++;
            if (re[i].num == '1') {
                i++;
            }
        } else if (re[i].num == 'n') {
            re[i].last = j - 1;
            i++;
        } else {
            if (i==0) {
                return 0;   // not match
            }

        }

        if (i >= len && j >= slen) {
            break;
        }
    }

    return 1;

}

int isMatch2(char *s, char *p) {

}