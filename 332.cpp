#include <vector>
#include <string>
#include <map>
#include <list>
#include <iostream>

using namespace std;

class Solution {
public:

    void print(const map<string, list<pair<string, int>>> &m) {
        for (auto p: m) {
            cout << p.first << ": ";
            for (const auto &n :p.second) {
                cout << n.first << "(" << n.second <<")" << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void insert(list<pair<string, int>> &l, string &s) {
        auto itr = l.begin();
        while (itr != l.end() && itr->first < s) {
            itr++;
        }
        l.insert(itr, make_pair(s, 0));
    }

    bool find(const string &s, map<string, list<pair<string, int>>> &m, int total, int cur, vector<string> &r) {
        if (total == cur) {
            r[cur] = s;
            return true;
        }
        for (auto &p: m[s]) {
            if (!p.second) {
                p.second = 1;
                bool valid = find(p.first, m, total, cur + 1, r);
                p.second = 0;
                if (valid) {
                    r[cur] = s;
                    return true;
                }
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, list<pair<string, int>>> m;
        for (auto t : tickets) {
            if (m.find(t.first) == m.end()) {
                list<pair<string, int>> l;
                m.insert(make_pair(t.first, l));
            }
            insert(m[t.first], t.second);
        }

        vector<string> r(tickets.size() + 1);

        find("JFK", m, tickets.size(), 0, r);

        return r;
    }
};

int main() {
    Solution s;

    vector<pair<string, string>> t = {
            make_pair("JFK", "SFO"), make_pair("JFK", "ATL"), make_pair("SFO", "ATL"), make_pair("ATL", "JFK"),
            make_pair("ATL", "SFO")
    };
    auto r = s.findItinerary(t);

    vector<pair<string, string>> t2 = {
            make_pair("JFK", "KUL"), make_pair("JFK", "NRT"), make_pair("NRT", "JFK")
    };
    auto r2 = s.findItinerary(t2);

    vector<pair<string, string>> t3 = {
            make_pair("EZE", "TIA"), make_pair("EZE", "HBA"), make_pair("AXA", "TIA"), make_pair("JFK", "AXA"),
            make_pair("ANU", "JFK"), make_pair("ADL", "ANU"), make_pair("TIA", "AUA"), make_pair("ANU", "AUA"),
            make_pair("ADL", "EZE"), make_pair("ADL", "EZE"), make_pair("EZE", "ADL"), make_pair("AXA", "EZE"),
            make_pair("AUA", "AXA"), make_pair("JFK", "AXA"), make_pair("AXA", "AUA"), make_pair("AUA", "ADL"),
            make_pair("ANU", "EZE"), make_pair("TIA", "ADL"), make_pair("EZE", "ANU"), make_pair("AUA", "ANU")
    };
    auto r3 = s.findItinerary(t3);

    return 0;
}