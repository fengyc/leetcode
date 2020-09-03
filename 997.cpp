#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<pair<int, int>> v(N);
        for (auto t : trust) {
            v[t[0] - 1].first += 1;     // egree
            v[t[1] - 1].second += 1;    // ingree
        }
        for (auto i = 0; i < v.size(); i++) {
            if (v[i].first == 0 && v[i].second == N - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};


int main() {
    vector<vector<int>> trust = {{1, 3},
                                 {1, 4},
                                 {2, 3},
                                 {2, 4},
                                 {4, 3}};
    int N = 4;

    Solution s;
    auto r = s.findJudge(N, trust);

    return 0;
}