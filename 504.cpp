#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        stringstream ss;
        auto is_negative = false;
        if (num < 0) {
            is_negative = true;
            num = -num;
        }

        while (num != 0) {
            auto r = num % 7;
            ss << r;
            num = num / 7;
        }

        if (is_negative) {
            ss << "-";
        }
        string s;
        ss >> s;
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution s;
    auto r1 = s.convertToBase7(100);
    auto r2 = s.convertToBase7(-7);
    return 0;
}