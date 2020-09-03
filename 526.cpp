class Solution {
public:
    int countArrangement(int N) {
        char a[16][16] = {0};
        for (int i = 1; i < 16; i++) {
            for (int j = i; j < 16; j++) {
                if (j % i == 0) {
                    a[i][j] = 1;
                    a[j][i] = 1;
                }
            }
        }

    }
};
