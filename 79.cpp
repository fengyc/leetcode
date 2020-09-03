#include <vector>
#include <list>
#include <string>

using namespace std;


class Solution {
public:

    bool exist(const vector<vector<char>> &b, vector<vector<bool>> &m, int r, int c, const string &word, int pos) {
        if (r < 0 || r >= b.size() || c < 0 || c >= b[0].size()) {
            return false;
        }
        if (m[r][c]) {
            return false;
        }
        if (word[pos] != b[r][c]) {
            return false;
        }
        m[r][c] = true;
        bool valid = true;
        if (pos < word.length() - 1) {
            valid = exist(b, m, r - 1, c, word, pos + 1);
            if (!valid) {
                valid = exist(b, m, r, c + 1, word, pos + 1);
            }
            if (!valid) {
                valid = exist(b, m, r + 1, c, word, pos + 1);
            }
            if (!valid) {
                valid = exist(b, m, r, c - 1, word, pos + 1);
            }
        }
        m[r][c] = false;
        return valid;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> m(rows);
        for (int i = 0; i < board.size(); i++) {
            m[i] = vector<bool>(cols);
        }
        list<pair<int, int>> l;
        bool valid = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (exist(board, m, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    vector<vector<char>> b = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };

    auto r = s.exist(b, "ABCCED");

    r = s.exist(b, "SEE");

    r = s.exist(b, "ABCB");

    return 0;
}

