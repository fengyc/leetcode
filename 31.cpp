#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            sort(nums.begin(), nums.end());
        }
    }
};

int main() {
    Solution s;

    vector<int> v = {
            5,4,3,2,1
    };

    s.nextPermutation(v);

    return 0;
}

