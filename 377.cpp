#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        auto *k = new uint64_t[target + 1];
        k[0] = 1;
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 1; i <= target; i++) {
            int sum = 0;
            for (auto n : nums) {
                if (i >= n) {
                    sum += k[i - n];
                }
            }
            k[i] = sum;
        }

        return k[target];
    }
};

int main() {
    Solution s;
    vector<int> v = {3, 33, 333};
    int target = 10000;

    auto r = s.combinationSum4(v, target);

    return 0;
}