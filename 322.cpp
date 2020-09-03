#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int *total = new int[amount + 1];
        total[0] = 0;
        for (int i = 1; i <= amount; i++) {
            total[i] = -1;
            int min = INT_MAX;
            for (auto c : coins) {
                if (i - c >= 0) {
                    if (total[i - c] != -1) {
                        min = min > total[i - c] ? total[i - c] : min;
                    }
                }
            }
            if (min != INT_MAX) {
                total[i] = min + 1;
            }
        }
        return total[amount];
    }
};

int main() {
    Solution s;
    vector<int> coins = {2};
    int amount = 3;

    auto r = s.coinChange(coins, amount);

    return 0;
}