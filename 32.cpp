#include <string>
#include <deque>

using namespace std;

class Solution {
public:

    struct Node {
        char c;
        bool match;
    };

    int longestValidParentheses(string s) {
        deque<bool> deque;

        int max = 0;
        for (auto c : s) {
            if (c == '(') {
                deque.push_back(false);
            } else {
                auto itr = deque.rbegin();
                while (itr != deque.rend() && *itr) {
                    itr++;
                }
                if (itr != deque.rend()) {
                    *itr = true;
                } else {
                    max = max < deque.size() ? deque.size() : max;
                    deque.clear();
                }
            }
        }

        for (auto itr = deque.begin(); itr != deque.end();) {
            if (*itr) {
                int count = 1;
                itr++;
                while (itr != deque.end() && *itr) {
                    count += 1;
                    itr++;
                }
                max = max < count ? count : max;
            } else {
                itr++;
            }
        }

        return max << 1;
    }
};

int main() {
    Solution s;
    string str(")()())()()(");

    auto r = s.longestValidParentheses(str);

    return 0;
}