// 拓扑排序，每次找入度为 0 的点

#include <stdlib.h>
#include <string.h>

struct N {
    int in;
    int val;
};

int *diStringMatch(char *S, int *returnSize) {
    int slen = strlen(S);
    *returnSize = slen + 1;

    struct N *inDegree = malloc(sizeof(struct N) * (slen + 1));
    for (int i = 0; i < slen + 1; i++) {
        inDegree[i].in = 0;
        inDegree[i].val = -1;
        if (i > 0 && S[i - 1] == 'I') {
            inDegree[i].in += 1;
        }
        if (i < slen && S[i] == 'D') {
            inDegree[i].in += 1;
        }
    }

    // find in 0
    int *nums = malloc(sizeof(int) * (slen + 1));
    int val = 0;
    while (val < slen + 1) {
        struct N *p = inDegree;
        while (p->in || p->val != -1) {
            p++;
        }
        int idx = p - inDegree;
        if (idx < slen && S[idx] == 'I') {
            inDegree[idx + 1].in -= 1;
        }
        if (idx > 0 && S[idx - 1] == 'D') {
            inDegree[idx - 1].in -= 1;
        }
        p->val = val;
        nums[idx] = val;
        val++;
    }

    free(inDegree);

    return nums;
}

int main() {
    char *s = "IDID";
    int size = 0;
    int *r = diStringMatch(s, &size);
    return 0;
}