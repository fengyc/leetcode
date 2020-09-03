#include <vector>
#include <stack>

using namespace std;

// skip list
//  The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100]

struct N {
    int temp;
    int day;
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        // skip list head, index is the temperature, head[i] is position
        int *head = (int *) calloc(101, sizeof(int));

        // 从后往前加
        for (int i = T.size() - 1; i >= 0; i--) {
            int temp = T[i];
            head[temp] = i;
            T[i] = 0;
            for (int j = temp + 1; j <= 100; j++) {
                if (head[j]) {
                    if (T[i] == 0) {
                        T[i] = head[j] - i;
                    } else {
                        T[i] = min(T[i], head[j] - i);
                    }
                    if (T[i] == 1) {
                        break;
                    }
                }
            }
        }

        return T;
    }

    vector<int> dailyTemperatures2(vector<int> &T) {
        stack<N> s;

        for (int i = 0; i < T.size(); i++) {
            if (s.empty()) {
                s.push({T[i], i});
                T[i] = 0;
            } else {
                while (!s.empty() && s.top().temp < T[i]) {
                    T[s.top().day] = i - s.top().day;
                    s.pop();
                }
                s.push({T[i], i});
                T[i] = 0;
            }
        }

        return T;
    }
};

int main() {
    Solution s;

    vector<int> t = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> r = s.dailyTemperatures2(t);

    return 0;
}

