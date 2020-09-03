#include <vector>

using namespace std;


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int count = 0;
        for (int i=0;i<rows;i++) {
            for (int j=0; j<cols;j++) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i-1][j] == 'X') {
                        continue;
                    }
                    if (j > 0 && board[i][j-1] == 'X' ) {
                        continue;
                    }
                    count ++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> board = {
            {'X', '.', '.', 'X'},
            {'.', '.', '.', 'X'},
            {'.', '.', '.', 'X'}
    };
    
    Solution s;
    
    int n = s.countBattleships(board);
    
    return 0;
}