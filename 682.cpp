#include <vector>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    int calPoints(vector<string> &ops) {
        vector<int> s;
        int top = -1;
        for (auto c : ops) {
            if (c[0] == 'C' && top >= 0) {
                s.pop_back();
                top--;
            } else if (c[0] == 'D' && top >= 0) {
                s.push_back(s[top] * 2);
                top++;
            } else if (c[0] == '+' && top > 0) {
                s.push_back(s[top - 1] + s[top]);
                top++;
            } else {
                int i = stoi(c);
                s.push_back(i);
                top++;
            }
        }
        int sum = 0;
        for (auto i : s) {
            sum += i;
        }
        return sum;
    }
};


int main() {
    Solution s;
    vector<string> ops = {
            "5","2","C","D","+"
    };
    int r = s.calPoints(ops);
    return 0;
}