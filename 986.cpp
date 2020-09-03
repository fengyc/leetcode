#include <vector>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector <Interval> intervalIntersection(vector <Interval> &A, vector <Interval> &B) {
        vector<Interval> r;
        auto a = A.begin();
        auto b = B.begin();
        while (a != A.end() && b != B.end()) {
            if ((*a).start > (*b).end) {
                b++;
                continue;
            }
            if ((*b).start > (*a).end) {
                a++;
                continue;
            }
            r.push_back(Interval(max((*a).start, (*b).start), min((*a).end, (*b).end)));
            if ((*a).end <= (*b).end) {
                a++;
            } else {
                b++;
            }
        }
        return r;
    }
};