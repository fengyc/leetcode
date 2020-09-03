#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int steps = R * C;
        vector<vector<int>> r(steps);
        r[0] = {r0, c0};
        int dir = 0;
        int x = c0;
        int y = r0;
        int path = 1;
        for (int i = 1; i < steps;) {
            if (dir == 0) {
                for (int j = 0; j < path && i < steps; j++) {
                    x += 1;
                    if (x >= 0 && x < C && y >=0 && y < R) {
                        r[i] = {y, x};
                        i++;
                    }
                }
                dir = 1;
            } else if (dir == 1) {
                for (int j = 0; j < path && i < steps; j++) {
                    y += 1;
                    if (x >= 0 && x < C && y >=0 && y < R) {
                        r[i] = {y, x};
                        i++;
                    }
                }
                dir = 2;
                path += 1;
            } else if (dir == 2) {
                for (int j = 0; j < path && i < steps; j++) {
                    x -= 1;
                    if (x >= 0 && x < C && y >=0 && y < R) {
                        r[i] = {y, x};
                        i++;
                    }
                }
                dir = 3;
            } else {
                for (int j = 0; j < path && i < steps; j++) {
                    y -= 1;
                    if (x >= 0 && x < C && y >=0 && y < R) {
                        r[i] = {y, x};
                        i++;
                    }
                }
                dir = 0;
                path += 1;
            }
        }
        return r;
    }
};

int main() {
    Solution s;

    vector<vector<int>> r = s.spiralMatrixIII(1, 4, 0, 0);

    return 0;
}