#include <string>
#include <map>

using namespace std;

class TimeMap {
public:

    map<string, map<int, string>> m;

    /** Initialize your data structure here. */
    TimeMap() : m() {
    }

    void set(string key, string value, int timestamp) {
        m[key].insert(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        auto search = m.find(key);
        if (search == m.end()) {
            return "";
        }
        auto pl = search->second.lower_bound(timestamp); // p.second >= timestamp
        if (pl != search->second.end()) {
            if (pl->first == timestamp) {
                return pl->second;
            }
        }
        auto rp = map<int, string>::reverse_iterator(pl);
        if (rp != search->second.rend()) {
            return rp->second;
        }
        return "";
    }
};

int main() {
    TimeMap s;

    s.set("foo", "bar", 1);
    auto r = s.get("foo", 1);
    r = s.get("foo", 3);
    s.set("foo", "bar2", 4);
    r = s.get("foo", 4);
    r = s.get("foo", 5);

    return 0;
}
