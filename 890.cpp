#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> result;
        for (auto &word : words) {
            map<char, char> m1;
            map<char, char> m2;
            auto c1_iter = word.begin();
            auto c2_iter = pattern.begin();
            bool match = true;
            while (c1_iter != word.end()) {
                char c1 = *c1_iter;
                char c2 = *c2_iter;
                auto m1_iter = m1.find(c1);
                if (m1_iter != m1.end() && c2 != (*m1_iter).second) {
                    match = false;
                    break;
                }
                auto m2_iter = m2.find(c2);
                if (m2_iter != m2.end() && c1 != (*m2_iter).second) {
                    match = false;
                    break;
                }
                m1[c1] = c2;
                m2[c2] = c1;
                c1_iter++;
                c2_iter++;
            }
            if (match) {
                result.push_back(word);
            }
        }
        return result;
    }
};

int main() {
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    Solution s;
    vector<string> result = s.findAndReplacePattern(words, "abb");
    return 0;
}