#include <vector>

using namespace std;


class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int rcA = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    rcA += 1;
                }
            }
        }

        int chA = 0;
        for (int i = 0; i < rows; i++) {
            int h = grid[i][0];
            for (int j = 0; j < cols; j++) {
                if (h < grid[i][j]) {
                    h = grid[i][j];
                }
            }
            chA += h;
        }

        int rhA = 0;
        for (int i = 0; i < cols; i++) {
            int h = grid[0][i];
            for (int j = 0; j < rows; j++) {
                if (h < grid[j][i]) {
                    h = grid[j][i];
                }
            }
            rhA += h;
        }

        return rcA + chA + rhA;
    }
};

int main() {
    Solution s;

    vector<vector<int>> g0 = {
            {2}
    };

    vector<vector<int>> g1 = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
    };

    vector<vector<int>> g2 = {
            {2, 2, 2},
            {2, 1, 2},
            {2, 2, 2}
    };

    int r = s.projectionArea(g0);

    return 0;
}

