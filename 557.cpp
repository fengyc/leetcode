#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<char> stack;
        string r;
        for (auto c : s) {
            if (c == ' ') {
                while (!stack.empty()) {
                    r.push_back(stack.top());
                    stack.pop();
                }
                r.push_back(' ');
            } else {
                stack.push(c);
            }
        }
        while (!stack.empty()) {
            r.push_back(stack.top());
            stack.pop();
        }
        return r;
    }
};

int main() {
    Solution s;
    string str("hello, world");

    auto r = s.reverseWords(str);

    return 0;
}