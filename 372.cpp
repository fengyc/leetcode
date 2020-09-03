#include <vector>
#include <map>

using namespace std;

/**
 * a^b % 1337 = r
 */
class Solution {
public:
    int mod(vector<int> &b, int r) {
        int m = 0;
        for (auto i : b) {
            m = (m * 10 + i) % r;
        }
        return m;
    }

    int superPow(int a, vector<int> &b) {
        if (a == 1337) {
            return 0;
        }

        int m[1337]; // k = a^x
        int n[1337]; // a^x = k
        for (int i = 0; i < 1337; i++) {
            m[i] = -1;
            n[i] = -1;
        }
        m[1] = 0;
        n[0] = 1;

        int i = 1;
        int p = -1;
        int q = -1;
        int fast = a % 1337;
        while (1) {
            int r = fast * n[i - 1] % 1337;
            if (m[r] != -1) {
                q = r;
                p = m[r];
                break;
            } else {
                m[r] = i;
                n[i] = r;
            }
            i++;
        }

        int r = mod(b, i - p);
        return n[r];

    }
};

int main() {
    Solution s;

    int a = 2147483647;
    vector<int> b = {2, 0, 0};

    auto r = s.superPow(a, b);

    return 0;
}