#include <vector>
#include <list>

using namespace std;

struct Node
{
    int passagers;
    int start;
    int end;
};

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int cap[1001] = {0};
        for (auto t = trips.begin(); t != trips.end(); t++)
        {
            auto p = (*t)[0];
            auto start = (*t)[1];
            auto end = (*t)[2];
            for (auto i = start; i < end; i++)
            {
                cap[i] += p;
                if (cap[i] > capacity)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> trips = {
        {3, 2, 7}, {3, 7, 9}, {8, 3, 9}};

    auto r = s.carPooling(trips, 11);

    return 0;
}
