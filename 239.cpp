#import <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.size() == 0) {
            return {};
        }

        vector<int> v;

        deque<int> dq;
        for (auto i = 0; i < k && i < nums.size(); i++) {
            dq.push_back(nums[i]);
        }
        sort(dq.begin(), dq.end());
        v.push_back(dq.back());

        for (auto i = k; i < nums.size(); i++) {
            auto to_remove = nums[i - k];
            auto p = lower_bound(dq.begin(), dq.end(), to_remove);
            dq.erase(p);

            auto to_add = nums[i];
            auto added = false;
            for (auto p = dq.begin(); p != dq.end(); p++) {
                if (*p >= to_add) {
                    dq.insert(p, to_add);
                    added = true;
                    break;
                }
            }
            if (!added) {
                dq.push_back(to_add);
            }

            v.push_back(dq.back());
        }

        return v;
    }
};


int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto k = 3;

    Solution s;
    auto r = s.maxSlidingWindow(nums, k);


    return 0;
}