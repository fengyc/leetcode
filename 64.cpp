#include <vector>
#include <limits>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int min = INT_MAX;
                if (i > 0) {
                    min = min > grid[i - 1][j] ? grid[i - 1][j] : min;
                }
                if (j > 0) {
                    min = min > grid[i][j - 1] ? grid[i][j - 1] : min;
                }
                min = min == INT_MAX ? 0 : min;
                grid[i][j] += min;
            }
        }
        return grid[rows - 1][cols - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    auto r = s.minPathSum(grid);
    return 0;
}

