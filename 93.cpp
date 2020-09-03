#include <string>
#include <vector>

using namespace std;


class Solution {
public:

    bool parse(const string &s, int pos, int part, vector<string> &v) {
        bool valid = false;
        for (int i = 1; i < 4 && pos + i <= s.length(); i++) {
            if (s[pos] == '0' && i > 1) {
                break;
            }
            int d = stoi(s.substr(pos, i));
            if (d > 255) {
                break;
            }
            if (pos + i == s.length() && part == 3) {
                v.push_back(s.substr(pos));
                return true;
            }
            vector<string> v2;
            if (part < 3 && parse(s, pos + i, part + 1, v2)) {
                for (int j = 0; j < v2.size(); j++) {
                    v.push_back(s.substr(pos, i) + "." + v2[j]);
                }
                valid = true;
            }
        }
        return valid;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        parse(s, 0, 0, r);
        return r;
    }
};


int main() {
    Solution s;
    auto r = s.restoreIpAddresses("25525511135");
    r = s.restoreIpAddresses("010010");
    return 0;
}
