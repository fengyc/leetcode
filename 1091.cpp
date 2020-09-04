#include <vector>
#include <list>

using namespace std;

// A*
class Solution
{
public:
    const int INF = 999999;
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
        {
            return -1;
        }

        int dist[100][100] = {{0}};
        for (auto i = 0; i < 100; i++)
        {
            for (auto j = 0; j < 100; j++)
            {
                dist[i][j] = INF;
            }
        }
        dist[0][0] = 1;

        list<pair<int, int>> s;
        s.push_back(make_pair(0, 0));

        while (!s.empty())
        {
            auto p = s.front();
            auto row = p.first;
            auto col = p.second;
            auto dist_p = dist[row][col];
            s.pop_front();

            // up
            if (row > 0 && grid[row - 1][col] == 0 && dist_p + 1 < dist[row - 1][col])
            {
                dist[row - 1][col] = dist_p + 1;
                s.push_back(make_pair(row - 1, col));
            }

            // up-right
            if (row > 0 && col + 1 < cols && grid[row - 1][col + 1] == 0 && dist_p + 1 < dist[row - 1][col + 1])
            {
                dist[row - 1][col + 1] = dist_p + 1;
                s.push_back(make_pair(row - 1, col + 1));
            }

            // right
            if (col + 1 < cols && grid[row][col + 1] == 0 && dist_p + 1 < dist[row][col + 1])
            {
                dist[row][col + 1] = dist_p + 1;
                s.push_back(make_pair(row, col + 1));
            }

            // right-down
            if (col + 1 < cols && row + 1 < rows && grid[row + 1][col + 1] == 0 && dist_p + 1 < dist[row + 1][col + 1])
            {
                dist[row + 1][col + 1] = dist_p + 1;
                s.push_back(make_pair(row + 1, col + 1));
            }

            // down
            if (row + 1 < rows && grid[row + 1][col] == 0 && dist_p + 1 < dist[row + 1][col])
            {
                dist[row + 1][col] = dist_p + 1;
                s.push_back(make_pair(row + 1, col));
            }

            // down-left
            if (col > 0 && row + 1 < rows && grid[row + 1][col - 1] == 0 && dist_p + 1 < dist[row + 1][col - 1])
            {
                dist[row + 1][col - 1] = dist_p + 1;
                s.push_back(make_pair(row + 1, col - 1));
            }

            // left
            if (col > 0 && grid[row][col - 1] == 0 && dist_p + 1 < dist[row][col - 1])
            {
                dist[row][col - 1] = dist_p + 1;
                s.push_back(make_pair(row, col - 1));
            }

            // left-up
            if (col > 0 && row > 0 && grid[row - 1][col - 1] == 0 && dist_p + 1 < dist[row - 1][col - 1])
            {
                dist[row - 1][col - 1] = dist_p + 1;
                s.push_back(make_pair(row - 1, col - 1));
            }

            if (dist[rows - 1][cols - 1] != INF)
            {
                return dist[rows - 1][cols - 1];
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> grid = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}};

    // auto r = s.shortestPathBinaryMatrix(grid);

    vector<vector<int>> grid2 = {
        {1, 0, 0}, {1, 1, 0}, {1, 1, 0}};

    auto r2 = s.shortestPathBinaryMatrix(grid2);

    return 0;
}
