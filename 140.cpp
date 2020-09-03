#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    vector<pair<bool, vector<string>>> cache;

    const vector<string> &wordBreak(const string &s, int pos, const vector<string> &dict) {
        if (!cache[pos].first) {
            bool valid = false;
            for (const auto &w:dict) {
                if (strncmp(s.c_str() + pos, w.c_str(), w.length()) == 0) {
                    valid = true;
                    if (pos + w.length() == s.length()) {
                        cache[pos].second.emplace_back(w);
                    } else {
                        auto r = wordBreak(s, pos + w.length(), dict);
                        for (const auto &i: r) {
                            cache[pos].second.emplace_back(w + " " + i);
                        }
                    }
                }
            }
        }
        cache[pos].first = true;
        return cache[pos].second;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        cache = vector<pair<bool, vector<string>>>(s.length());
        vector<string> r;
        r = wordBreak(s, 0, wordDict);
        return r;
    }
};

int main() {
    Solution s;

    vector<string> d = {
            "cat", "cats", "and", "sand", "dog"
    };
    string t = "catsanddog";
    auto r = s.wordBreak(t, d);

    d = {
            "apple", "pen", "applepen", "pine", "pineapple"
    };
    t = "pineapplepenapple";
    r = s.wordBreak(t, d);

    t = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    d = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    r = s.wordBreak(t, d);

    return 0;
}