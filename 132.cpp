#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    vector<vector<pair<bool, bool>>> m;

    // DP
    bool check(const string &s, int l, int r) {
        if (!m[l][r].first) {
            if (l == r) {
                m[l][r].second = true;
            }
            else if (r - l == 1) {
                if (s[l] == s[r]) {
                    m[l][r].second = true;
                }
            } else {
                if (check(s, l + 1, r - 1) && s[l] == s[r]) {
                    m[l][r].second = true;
                }
            }
            m[l][r].first = true;
        }
        return m[l][r].second;
    }

    int minCut(string s) {
        m = vector<vector<pair<bool, bool>>>(s.length());
        for (auto &v : m) {
            v = vector<pair<bool, bool>>(s.length());
        }
        queue<int> q;
        int count = 0;
        q.push(0);
        while (true) {
            queue<int> q2;
            while (!q.empty()) {
                int idx = q.front();
                q.pop();
                for (int i = idx; i < s.length(); i++) {
                    if (check(s, idx, i)) {
                        if (i == s.length() - 1) {
                            return count;
                        }
                        q2.push(i + 1);
                    }
                }
            }
            q = q2;
            count++;
        }
    }
};

int main() {
    Solution s;

    auto r = s.minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");

    return 0;
}
