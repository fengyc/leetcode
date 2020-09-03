#include <vector>

using namespace std;


class Solution {
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        int steps = abs(target[0]) + abs(target[1]);
        for (auto g:ghosts) {
            if (abs(g[0] - target[0]) + abs(g[1] - target[1]) <= steps) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    vector<vector<int>> g = {
            {2, 0}
    };
    vector<int> t = {1, 0};

    bool r = s.escapeGhosts(g, t);

    return 0;
}
