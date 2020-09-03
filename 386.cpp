#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> r;
        list<int> s;

        r.reserve(n);

        for (auto i = 9; i > 0; i--) {
            if (i <= n) {
                s.push_back(i);
            }
        }

        while (!s.empty()) {
            auto last = s.back();
            r.push_back(last);
            s.pop_back();

            auto next_base = last * 10;
            if (next_base > n) {
                continue;
            }

            for (auto i = 9; i >= 0; i--) {
                auto next = next_base + i;
                if (next > n) {
                    continue;
                }
                s.push_back(next);
            }
        }

        return r;
    }
};

class Solution2 {
public:

    void calc(vector<int> &v, int &n) {
        auto base = v.back() * 10;
        for (auto i = 0; i <= 9; i++) {
            auto next = base + i;
            if (next > n) {
                break;
            }
            v.push_back(next);
            calc(v, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> r;
        r.reserve(n);

        for (auto i = 1; i <= 9 && i <= n; i++) {
            r.push_back(i);
            calc(r, n);
        }

        return r;
    }
};

int main() {

    int n = 10000;
    Solution s;
    auto r = s.lexicalOrder(n);

    Solution2 s2;
    auto r2 = s2.lexicalOrder(n);

    if (r.size() != r2.size()) {
        printf("failed\n");
    }
    for (auto i = 0; i < r.size(); i++) {
        if (r[i] != r2[i]) {
            printf("failed\n");
        }
    }
    printf("success\n");

    return 0;
}
