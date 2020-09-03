//
// Created by 冯英才 on 2019-07-22.
//

class Solution {
public:
    int minSteps(int n) {
        int k[1001];
        k[1] = 0;
        for (int i = 2; i <= n; i++) {
            k[i] = i;
            for (int j = 2; j < i / 2; j++) {
                if (i % j == 0) {
                    k[i] = k[i / j] + j;
                    break;
                }
            }
        }
        return k[n];
    }
};

int main() {
    Solution s;
    auto r1 = s.minSteps(1000);
    return 0;
}