#include <vector>

using namespace std;


class Solution {
public:

    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second < b.second) {
            return true;
        }
        if (a.second == b.second && a.first < b.first) {
            return true;
        }
        return false;
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        sort(people.begin(), people.end(), comp);

        for (int i = 1; i < people.size(); i++) {
            int count = 0;
            pair<int, int> cur = people[i];
            for (int j = 0; j < i; j++) {
                if (people[j].first < cur.first) {
                    continue;
                }
                count++;
                if (count == cur.second) {
                    do {
                        j++;
                    } while (people[j].first < cur.first && j < i);
                    if (j < i) {
                        for (int k = i; k > j; k--) {
                            people[k] = people[k - 1];
                        }
                        people[j] = cur;
                    }
                    break;
                }
            }
        }

        return people;
    }
};


int main() {
    Solution s;

    vector<pair<int, int>> p = {
            make_pair(7, 0), make_pair(4, 4), make_pair(7, 1), make_pair(5, 0), make_pair(6, 1), make_pair(5, 2)
    };

    vector<pair<int, int>> r = s.reconstructQueue(p);

    return 0;
}