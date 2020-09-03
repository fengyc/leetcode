int isPalindrome(int x) {
    if (x < 0) {
        return 0;
    }
    char s[32];
    int len = 0;
    while (x > 0) {
        s[len++] = x % 10;
        x = x/10;
    }
    int low = 0;
    int high = len -1;
    while (low < high) {
        if (s[low] != s[high]) {
            return 0;
        }
    }
    return 1;
}

int main() {

}