#include <vector>

using namespace std;


class Solution {
public:
    vector<int> v;

    int fib(int N) {
        if (v.size() == 0) {
            v = vector<int>(N+2);
            v[0] = 0;
            v[1] = 1;
        }
        if (v[N] || N < 2) {
            return v[N];
        }
        v[N] = fib(N-1) + v[N-2];
        return v[N];
    }
};

int main() {
    Solution s;

    int r = s.fib(0);

    return 0;
}


