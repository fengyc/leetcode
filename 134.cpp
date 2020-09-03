
#import <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> v(gas.size());

        for (auto i = 0; i < gas.size(); i++) {
            v[i] = gas[i] - cost[i];
        }

        for (auto i = 0; i < v.size(); i++) {
            auto sum = 0;
            for (auto j = 0; j < v.size(); j++) {
                sum += v[(i + j) % v.size()];
                if (sum < 0) {
                    break;
                }
                if (j == v.size() - 1) {
                    return i;
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};

    Solution s;
    auto r = s.canCompleteCircuit(gas, cost);

    return 0;
}