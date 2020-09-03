#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> r(len1 + len2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < len2; i++) {
            for (int j = 0; j < len1; j++) {
                int d = (num2[i] - '0') * (num1[j] - '0');
                r[i + j] = r[i + j] + d;
                for (int k = i + j; r[k] > 9;) {
                    int rk = r[k];
                    r[k] = rk % 10;
                    r[k + 1] += rk / 10;
                    k += 1;
                }
            }
        }
        reverse(r.begin(), r.end());
        int p = 0;
        string s;
        s.reserve(len1 + len2);
        while (p < r.size() && r[p] == 0) {
            p += 1;
        }
        while (p < r.size()) {
            s.push_back('0' + r[p++]);
        }
        if (s.size() == 0) {
            return "0";
        }
        return s;
    }
};

int main() {
    Solution s;
    auto r = s.multiply("0", "99");
    return 0;
}

