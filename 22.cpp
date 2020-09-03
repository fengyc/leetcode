#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

    vector<string> gen(int n) {
        vector<string> r;
        if (n == 0) {
            r.emplace_back("");
        } else {
            for (int i = 0; i < n; i++) {
                auto left = gen(n - i - 1);
                auto right = gen(i);
                for (auto s1 : left) {
                    for (auto s2 : right) {
                        r.emplace_back("(" + s1 + ")" + s2);
                    }
                }
            }
        }
        return r;
    }

    void gen2(vector<vector<string>> &m, int n) {
        if (m.size() > n) {
            return;
        }

        vector<string> r;
        for (int i = 0; i < n; i++) {
            gen2(m, n - i - 1);
            gen2(m, i);
            for (auto s1 : m[n - i - 1]) {
                for (auto s2 : m[i]) {
                    r.emplace_back("(" + s1 + ")" + s2);
                }
            }
        }
        m.push_back(r);
    }


    vector<string> generateParenthesis(int n) {
        vector<vector<string>> m;
        m.push_back({""});
        gen2(m, n);
        return m[n];
    }
};

int main() {
    Solution s;
    auto r = s.generateParenthesis(3);
    return 0;
}