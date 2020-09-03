#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        int count = 0;
        for (auto c : S) {
            if (!s.empty() && (s.top() == '(' && c == ')')) {
                s.pop();
            } else {
                s.push(c);
            }
        }
        return s.size();
    }
};

int main() {
    string S = "()))((";
    Solution s;
    int n = s.minAddToMakeValid(S);
    return 0;
}