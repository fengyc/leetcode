#include <string>

using namespace std;

class Solution {
public:

    int findK(int pre, int n, int *k) {
        *k -= 1;
        if (*k == 0) {
            return pre;
        }
        if (pre <= n / 10) {
            pre = pre * 10;
            for (int i = 0; i < 10 && pre + i < n; i++) {
                int num = findK(pre + i, n, k);
                if (num) {
                    return num;
                }
            }
        }
        return 0;
    }

    int findKthNumber(int n, int k) {
        int tmpk = k;
        int num = 0;
        for (int i = 1; i < 10; i++) {
            num = findK(i, n, &tmpk);
            if (num) {
                break;
            }
        }
        return num;
    }
};

int main() {
    Solution s;

    auto r = s.findKthNumber(596516650, 593124772);

    return 0;
}
