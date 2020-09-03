#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;


class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        map<string, int> m;

        for (auto p = cpdomains.begin(); p != cpdomains.end(); p++) {
            int pos = p->find(' ');
            string count = p->substr(0, pos);
            int n = stoi(count);

            string domain = p->substr(pos + 1);
            while (domain.length() > 0) {
                auto kv = m.find(domain);
                if (kv != m.end()) {
                    kv->second += n;
                } else {
                    m[domain] = n;
                }

                int dot = domain.find('.');
                if (dot != string::npos) {
                    domain = domain.substr(dot + 1);
                } else {
                    break;
                }
            }
        }

        vector<string> r;
        for (auto kv = m.begin(); kv != m.end(); kv++) {
            stringstream ss;
            ss << kv->second << " " << kv->first;
            r.push_back(ss.str());
        }

        return r;
    }
};


int main() {
    vector<string> v = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    Solution s;
    auto r = s.subdomainVisits(v);
    return 0;
}