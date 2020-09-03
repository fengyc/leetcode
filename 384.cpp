#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        srand(0);
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        while (!steps.empty()) {
            auto step = steps.top();
            auto c = this->nums[step.first];
            this->nums[step.first] = this->nums[step.second];
            this->nums[step.second] = c;
            steps.pop();
        }
        return this->nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto a = rand() % this->nums.size();
        auto b = rand() % this->nums.size();
        auto c = this->nums[a];
        this->nums[a] = this->nums[b];
        this->nums[b] = c;
        this->steps.push(make_pair(a, b));
        return this->nums;
    }

private:
    stack<pair<int, int>> steps;
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
    vector<int> nums = {1,2,3,4,5,6};

    Solution s(nums);
    auto r = s.shuffle();
    auto r2 = s.reset();

    return 0;
}