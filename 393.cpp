#include <vector>

using namespace std;

/**
 * Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 */

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        auto bytes = 0;
        for (auto c : data) {
            if (bytes == 0) {
                if ((c & 0x80) == 0) {
                    continue;
                }
                if ((c & 0xE0) == 0xC0) {
                    bytes = 1;
                    continue;
                }
                if ((c & 0xF0) == 0xE0) {
                    bytes = 2;
                    continue;
                }
                if ((c & 0xF8) == 0xF0) {
                    bytes = 3;
                    continue;
                }
                return false;
            }
            else {
                if ((c & 0xC0) == 0x80) {
                    bytes -= 1;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> data = {197, 130, 1};
    vector<int> data2 = {235, 140, 4};
    Solution s;
    auto r = s.validUtf8(data);
    auto r2 = s.validUtf8(data2);
    return 0;
}