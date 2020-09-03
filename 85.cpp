#import <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        vector<int> row(matrix[0].size());
        auto max = 0;
        for (auto r : matrix) {
            for (auto i = 0; i < r.size(); i++) {
                if (r[i] == '1') {
                    row[i] += 1;
                } else {
                    row[i] = 0;
                }
            }
            for (auto i = 0; i < row.size(); i++) {
                int n = 1;
                for (auto j = i + 1; j < row.size() && row[j] >= row[i]; j++) {
                    n++;
                }
                for (auto j = i - 1; j >= 0 && row[j] >= row[i]; j--) {
                    n++;
                }
                auto area = n * row[i];
                max = max > area ? max : area;
            }
        }
        return max;
    }
};

int main() {
    vector<vector<char>> matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
    };

    Solution s;
    auto n = s.maximalRectangle(matrix);

    return 0;
}

