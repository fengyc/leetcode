#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> r(num + 1);
        r[0] = 0;
        int k = 0;
        for (int i = 1; i <= num; i++) {
            r[i] = r[k++] + 1;
            if (k > (i >> 1)) {
                k = 0;
            }
        }
        return r;
    }
};

int main() {
    Solution s;

    vector<int> r = s.countBits(5);

    return 0;
}