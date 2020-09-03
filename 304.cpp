#include <vector>

using namespace std;


class NumMatrix {
public:
    vector<vector<int>> dp;

    NumMatrix(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return;
        }

        int cols = matrix[0].size();

        for (int i = 0; i <= rows; i++) {
            dp.emplace_back(cols + 1);
            dp[i][0] = 0;
        }
        for (int j = 0; j <= cols; j++) {
            dp[0][j] = 0;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] + matrix[i][j] - dp[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> v = {
            {1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5}
    };
    NumMatrix m(v);

    auto r = m.sumRegion(1, 3, 3, 4);

    return 0;
}