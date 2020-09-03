#include <string>

using namespace std;


class Solution {
public:

    string pick(string num, int remains) {
        int len = num.length();
        if (remains <= 0) {
            return "";
        }
        if (remains >= len) {
            return num;
        }
        int prelen = len - remains + 1;
        int minIdx = 0;
        char min = num[0];
        for (int i = 0; i < prelen; i++) {
            if (num[i] < min) {
                minIdx = i;
                min = num[i];
            }
        }
        return min + pick(num.substr(minIdx + 1), remains - 1);
    }

    string removeKdigits(string num, int k) {
        int remains = num.length() - k;
        string s = pick(num, remains);
        if (s.length() == 0) {
            return "0";
        }
        int offset = 0;
        while (offset < s.length() - 1 && s[offset] == '0') {
            offset++;
        }
        return s.substr(offset);
    }
};


int main() {
    Solution s;

    auto r = s.removeKdigits("140320219", 6);

    return 0;
}