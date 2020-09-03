#include <vector>

using namespace std;

/**
 * 左边的数总是要尽量为 1
 *
 * A[i] 第一列全部变化 1 后，其它各列的 A'[i][j] 为 A[i][j]^A[i][0]
 *
 * 只需要对每列的 0/1 数比较一下看看那个大，决定此列是否翻转，i=k 时，max(sum(A[i][j]， cols - sum(A[i][j]))
 *
 */
class Solution {
public:
    int matrixScore(vector<vector<int>> &A) {
        int rows = A.size();
        int cols = A[0].size();
        int sum = 0;
        for (int c = 0; c < cols; c++) {
            int n = 0;
            for (int r = 0; r < rows; r++) {
                n += A[r][c] ^ A[r][0];
            }
            sum += max(n, rows - n) << (cols - c - 1);
        }
        return sum;
    }
};