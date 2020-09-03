#include <vector>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> sa, sb;
        // split
        int oldpos = 0;
        int pos = A.find(' ', oldpos);
        while (pos != string::npos) {
            string part = A.substr(oldpos, pos - oldpos);
            sa.push_back(part);
            oldpos = pos + 1;
            pos = A.find(' ', oldpos);
        }
        sa.push_back(A.substr(oldpos));

        oldpos = 0;
        pos = B.find(' ', oldpos);
        while (pos != string::npos) {
            string part = B.substr(oldpos, pos - oldpos);
            sb.push_back(part);
            oldpos = pos + 1;
            pos = B.find(' ', oldpos);
        }
        sa.push_back(B.substr(oldpos));

        vector<string> r;

        for (int i = 0; i < sa.size() - 1; i++) {

        }

        return r;
    }
};