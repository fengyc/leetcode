#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for (auto i : nums) {
            if (s.find(i) != s.end()) {
                s.erase(i);
                continue;
            }
            s.insert(i);
        }
        return *s.begin();
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for (auto n : nums) {
            r ^= n;
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 3, 2, 4, 4, -3, -3};
    auto r = s.singleNumber(nums);
    return 0;
}