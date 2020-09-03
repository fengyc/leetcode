#include <vector>

using namespace std;


class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    if (i == 0 || grid[i - 1][j] == 0) {
                        count += 1;
                    }
                    if (j == cols - 1 || grid[i][j + 1] == 0) {
                        count += 1;
                    }
                    if (i == rows - 1 || grid[i + 1][j] == 0) {
                        count += 1;
                    }
                    if (j == 0 || grid[i][j - 1] == 0) {
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
};

int main() {

    Solution s;

    vector<vector<int>> g = {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0}
    };

    int c = s.islandPerimeter(g);

    return 0;
}

