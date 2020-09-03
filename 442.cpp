#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        int len = nums.size();
        vector<int> r;

        for (int i = 0; i < len; i++) {
            while (nums[i] > 0) {
                int k = nums[i];
                if (k == i + 1) {
                    nums[i] = -1;
                } else if (nums[k - 1] >= 0) {
                    nums[i] = nums[k - 1];
                    nums[k - 1] = -1;
                } else {
                    r.push_back(k);
                    nums[i] = 0;
                }
            }
        }

        return r;
    }
};

int main() {

    vector<int> n = {
            4,3,2,7,8,2,3,1
    };

    Solution s;

    vector<int> r = s.findDuplicates(n);

    return 0;
}