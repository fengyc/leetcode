#include <string>

using namespace std;

int f[256] = {0};


class Solution {
public:
    static bool cmp(const char c1, const char c2) {
        if (f[c1] != f[c2]) {
            return f[c1] > f[c2];
        }
        return c1 > c2;
    }

    string frequencySort(string s) {
        memset(f, 0, sizeof(f));
        for (auto c: s) {
            f[c] += 1;
        }
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

int main() {
    Solution s;

    string v = "tree";

    s.frequencySort(v);

    return 0;

}
