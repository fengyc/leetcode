#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

    void flip(vector<int> &v, int n) {
        for (int i = 0; i < (n >> 1); i++) {
            int tmp = v[i];
            v[i] = v[n - i - 1];
            v[n-i-1] = tmp;
        }
    }

    vector<int> pancakeSort(vector<int> &A) {
        vector<int> B(A);
        vector<int> r;

        sort(B.begin(), B.end());

        for (int i = A.size() - 1; i > 0; i--) {
            if (A[i] != B[i]) {
                for (int j = 0; j <= i; j++) {
                    if (B[j] == A[i]) {
                        flip(B, j+1);
                        flip(B, i+1);
                        if (j) {
                            r.push_back(j+1);
                        }
                        r.push_back(i+1);
                        break;
                    }
                }
            }
        }

        flip(r, r.size());
        return r;
    }
};

int main() {

    vector<int> v = {1, 2, 3, 4};

    Solution s;

    vector<int> r = s.pancakeSort(v);

    return 0;
}