#include <string>
#include <queue>
#include <map>
#include <set>
#include <sstream>

using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream ss;
        queue<char> q;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) {
            ss << "-";
        }
        long n = abs((long) numerator);
        long d = abs((long) denominator);
        long r = n / d;
        long m = n % d;
        ss << r;
        if (m) {
            ss << ".";
        }
        map<long, long> ms;
        int idx = 0;
        while (m != 0) {
            ms.insert(make_pair(m, idx++));
            n = m * 10;
            r = n / d;
            m = n % d;
            ss << r;
            if (ms.find(m) != ms.end()) {
                break;
            }
        }
        string s;
        ss >> s;
        if (m != 0) {
            idx = ms.find(m)->second;
            int offset = s.find('.');
            s.insert(offset + idx + 1, 1, '(');
            s.append(1, ')');
            return s;
        }
        return s;
    }
};

int main() {
    Solution s;
    auto r = s.fractionToDecimal(1, 214748364);
    return 0;
}