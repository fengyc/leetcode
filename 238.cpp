#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> v(nums.size());
        vector<pair<int, int>> buf(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                buf[i] = make_pair(1, 0);
            } else {
                buf[i] = make_pair(buf[i - 1].first * nums[i - 1], 0);
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                buf[i].second = 1;
            } else {
                buf[i].second = buf[i + 1].second * nums[i + 1];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            v[i] = buf[i].first * buf[i].second;
        }

        return v;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;

    auto r = s.productExceptSelf(nums);

    return 0;
}