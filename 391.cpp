#include <vector>

using namespace std;


class Solution {
public:

    bool overlap(vector<int> &rect1, vector<int> &rect2) {
        int bl_x = max(rect1[0], rect2[0]);
        int bl_y = max(rect1[1], rect2[1]);
        int tr_x = min(rect1[2], rect2[2]);
        int tr_y = min(rect1[3], rect2[3]);

        if (tr_x > bl_x && tr_y > bl_y) {
            return true;
        }
        return false;
    }

    long long area(vector<int> &rect) {
        return (rect[2] - rect[0]) * (rect[3] - rect[1]);
    }

    bool isRectangleCover(vector<vector<int>> &rectangles) {
        int bl_x = rectangles[0][0];
        int bl_y = rectangles[0][1];
        int tr_x = rectangles[0][2];
        int tr_y = rectangles[0][3];
        long long total_area = 0;

        for (int i = 0; i < rectangles.size(); i++) {
            total_area += area(rectangles[i]);
            bl_x = min(bl_x, rectangles[i][0]);
            bl_y = min(bl_y, rectangles[i][1]);
            tr_x = max(tr_x, rectangles[i][2]);
            tr_y = max(tr_y, rectangles[i][3]);

            for (int j = i + 1; j < rectangles.size(); j++) {
                if (overlap(rectangles[i], rectangles[j])) {
                    return false;
                }
            }
        }

        long long area = (tr_x - bl_x) * (tr_y - bl_y);
        return area == total_area;
    }
};

int main() {
    Solution s;

    vector<vector<int>> rectangles1 = {
            {1, 1, 3, 3},
            {3, 1, 4, 2},
            {3, 2, 4, 4},
            {1, 3, 2, 4},
            {2, 3, 3, 4}
    };
    auto r1 = s.isRectangleCover(rectangles1);

    vector<vector<int>> rectangles2 = {
            {1, 1, 3, 3},
            {3, 1, 4, 2},
            {1, 3, 2, 4},
            {3, 2, 4, 4}
    };
    auto r2 = s.isRectangleCover(rectangles2);

    vector<vector<int>> rectangles3 = {
            {1, 1, 3, 3},
            {3, 1, 4, 2},
            {1, 3, 2, 4},
            {2, 2, 4, 4}
    };
    auto r3 = s.isRectangleCover(rectangles3);

    vector<vector<int>> rectangles4 = {
            {0, 0, 4, 1},
            {7, 0, 8, 2},
            {6, 2, 8, 3},
            {5, 1, 6, 3},
            {4, 0, 5, 1},
            {6, 0, 7, 2},
            {4, 2, 5, 3},
            {2, 1, 4, 3},
            {0, 1, 2, 2},
            {0, 2, 2, 3},
            {4, 1, 5, 2},
            {5, 0, 6, 1}
    };
    auto r4 = s.isRectangleCover(rectangles4);

    vector<vector<int>> rectangle5 = {
            {0, 0, 1, 1},
            {0, 1, 3, 2},
            {1, 0, 2, 2}
    };
    auto r5 = s.isRectangleCover(rectangle5);

    return 0;
}