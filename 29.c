#include <math.h>

int divide(int dividend, int divisor) {
    if (divisor < 0 ) {
        divisor = - divisor;
        dividend = - dividend;
    }

    int sum = 0;
    int r = 0;

    if (sum < dividend) {
        while (sum < dividend) {
            sum += divisor;
            if (sum > dividend) {
                return r;
            }
            r++;
        }
    }
    else if (sum > dividend) {
        while(sum > dividend) {
            sum -= divisor;
            r--;
            if (sum < dividend) {
                return r;
            }
        }
    }
    return r;
}

int main() {
    int r = divide(10, 3);
    r = divide(2, 3);
    r = divide(-10, 3);
    r = divide(-1, -3);
    return 0;
}