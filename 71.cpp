#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;

        while (true) {
            int pos = path.find('/');
            if (pos == string::npos) {
                if (!path.empty()) {
                    s.push_back(path);
                }
                break;
            }

            string part = path.substr(0, pos);
            if (part == ".") {}
            else if (part == "..") {
                if (s.size()) {
                    s.pop_back();
                }
            }
            else {
                if (!part.empty()) {
                    s.push_back(part);
                }
            }

            path = path.substr(pos + 1);
        }

        string r("/");
        while (!s.empty()) {
            r += s.front();
            s.pop_front();
            if (!s.empty()) {
                r += "/";
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    string s1("/home//foo");
    string r;

    r = s.simplifyPath(s1);

    string s2("/home/../foo//");
    r = s.simplifyPath(s2);

    string s3("//./foo//.././bar");
    r = s.simplifyPath(s3);

    string s4("/../");
    r = s.simplifyPath(s4);

    string s5("/a//b////c/d//././/..");
    r = s.simplifyPath(s5);

    return 0;
}