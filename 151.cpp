#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string r;
        int len = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                len++;
            } else {
                if (len) {
                    if (r.length() > 0) {
                        r.append(" ");
                    }
                    r.append(s.substr(i + 1, len));
                    len = 0;
                }
            }
        }
        if (s[0] != ' ') {
            if (r.length() > 0) {
                r.append(" ");
            }
            r.append(s.substr(0, len));
        }
        return r;
    }
};

int main() {
    Solution s;
    auto r = s.reverseWords("  hello  world!  ");
    r = s.reverseWords("Hello ,  world!  ");
    return 0;
}