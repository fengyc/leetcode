#include <vector>

using namespace std;

class Solution {
public:

    bool path(vector<vector<int>> &g, int v, vector<int> *p) {
        if (v == g.size() - 1) {
            p->push_back(v);
            return true;
        }

        vector<vector<int>> r;
        for (auto e : g[v]) {
            vector<int> t;
            t.push_back(v);

            if (path(g, e, &t)) {

            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> r;


    }
};