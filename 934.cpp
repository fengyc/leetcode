#include <vector>
#include <list>

using namespace std;

class Solution {
public:

    class Node {
    public:
        int x;
        int y;

        Node(int x, int y) : x(x), y(y) {}
    };


    struct Point {
        int val;
        int visit;
    };

    void visit(list<Node> &l, int x, int y, vector<vector<Point>> &m) {
        if (x >= 0 && x < m.size() && y >= 0 && y < m[0].size()) {
            if (m[x][y].val && !m[x][y].visit) {
                l.emplace_back(x, y);
                m[x][y].visit = 1;

                visit(l, x - 1, y, m);
                visit(l, x, y + 1, m);
                visit(l, x + 1, y, m);
                visit(l, x, y - 1, m);
            }
        }
    }

    int shortestBridge(vector<vector<int>> &A) {
        int rows = A.size();
        int cols = A[0].size();

        // 转换
        vector<vector<Point>> matrix(A.size());
        for (int i = 0; i < rows; i++) {
            matrix[i] = vector<Point>(cols);
            for (int j = 0; j < cols; j++) {
                Point p{A[i][j], 0};
                matrix[i][j] = p;
            }
        }

        // 分成两个集合
        list<Node> a;
        list<Node> b;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j].val) {
                    if (!matrix[i][j].visit) {
                        if (a.size() == 0) {
                            visit(a, i, j, matrix);
                        } else {
                            visit(b, i, j, matrix);
                        }
                    }
                }
            }
        }

        // 计算集合最小距离
        int min = INT_MAX;
        for (auto i = a.begin(); i != a.end(); i++) {
            for (auto j = b.begin(); j != b.end(); j++) {
                int dist = abs(i->x - j->x) + abs(i->y - j->y) - 1;
                min = dist < min ? dist : min;
            }
        }

        return min;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
    };

    auto r = s.shortestBridge(v);

    return 0;
}
