#include <vector>
#include <string>

using namespace std;


class Solution {
public:

    void fill(vector<vector<char>>& matrix, int rows, int cols, int i, int j) {
        matrix[i][j] = 1;
        if (i>0 && matrix[i-1][j] == 0) {
            fill(matrix, rows, cols, i-1, j);
        }
        if (j<cols-1 && matrix[i][j+1] == 0) {
            fill(matrix, rows, cols, i, j+1);
        }
        if (i<rows-1 && matrix[i+1][j] == 0) {
            fill(matrix, rows, cols, i+1, j);
        }
        if (j>0 && matrix[i][j-1] == 0) {
            fill(matrix, rows, cols, i, j-1);
        }
    }

    int regionsBySlashes(vector<string> &grid) {
        // grid -> 3*3 grid
        int grows = grid.size();
        int gcols = grid[0].length();
        int mrows = grows * 3;
        int mcols = gcols * 3;

        vector<vector<char>> matrix(mrows);
        for (int i = 0; i < mrows; i++) {
            matrix[i] = vector<char>(mcols);
        }

        for (int i = 0; i < grows; i++) {
            for (int j = 0; j < gcols; j++) {
                int mi = i*3;
                int mj = j*3;
                switch (grid[i][j]) {
                    case '/':
                        matrix[mi][mj+2] = 1;
                        matrix[mi+1][mj+1] = 1;
                        matrix[mi+2][mj] = 1;
                        break;
                    case '\\':
                        matrix[mi][mj] = 1;
                        matrix[mi+1][mj+1] = 1;
                        matrix[mi+2][mj+2] = 1;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < mrows; i++) {
            for (int j = 0; j < mcols; j++) {
                if (matrix[i][j] == 0) {
                    fill(matrix, mrows, mcols, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {

    vector<string> grid1 = {
            "//",
            "/ "
    };

    Solution s;

    int r = s.regionsBySlashes(grid1);

    return 0;
}
