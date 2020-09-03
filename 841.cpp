#include <vector>

using namespace std;

/**
 * 1 <= rooms.length <= 1000
 * 0 <= rooms[i].length <= 1000
 */

class Solution {
public:

    void visit(vector<vector<int>> &rooms, int r, char *visited) {
        if (visited[r]) {
            return;
        }
        visited[r] = 1;
        vector<int> keys = rooms[r];
        for (auto key: keys) {
            visit(rooms, key, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        char *visisted = (char *)calloc(rooms.size(), sizeof(char));
        visit(rooms, 0, visisted);
        for (int i = 0; i < rooms.size(); i++) {
            if (!visisted[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    Solution s;

    vector<vector<int>> r = {
            {1, 3},
            {3, 0, 1},
            {2},
            {0}
    };

    bool k = s.canVisitAllRooms(r);

    return 0;
}