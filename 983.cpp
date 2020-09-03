#include <vector>

using namespace std;

class Solution {
public:

    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int total[366] = {0};   // total[k] is min total cost of day k

        int day = 1;
        auto itr = days.begin();
        for (day = 1; day <= 365 && itr != days.end(); day++) {
            int t = total[day - 1];
            if (*itr == day) {
                int t1 = total[day - 1] + costs[0];

                int prev7 = day >= 7 ? total[day - 7] : 0;
                int t7 = prev7 + costs[1];

                int prev30 = day >= 30 ? total[day - 30] : 0;
                int t30 = prev30 + costs[2];

                t = min(t1, t7);
                t = min(t, t30);
                itr++;
            }

            total[day] = t;
        }

        return total[*days.rbegin()];
    }
};

int main() {
    Solution s;
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};

    int r = s.mincostTickets(days, costs);

    vector<int> days2 = {1, 4, 5, 6, 7, 8, 9, 10, 30, 31, 32, 33};
    auto r2 = s.mincostTickets(days2, costs);

    return 0;
}