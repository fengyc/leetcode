#include <string>
#include <vector>
#include <list>
#include <sstream>

using namespace std;


class Solution {
public:

    static bool cmp(const string &s1, const string &s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int i1 = 0, i2 = 0;
        for(int i=0;i<max(len1, len2); i++) {
            if (s1[i1] > s2[i2]) {
                return true;
            }
            if (s1[i1] < s2[i2]) {
                return false;
            }
            i1 = (i1 + 1) % len1;
            i2 = (i2 + 1) % len2;
        }
        return len1 < len2;
    }

    string largestNumber(vector<int> &nums) {
        vector<list<string>> v(10);
        for (auto i : nums) {
            stringstream ss;
            ss << i;
            string s;
            ss >> s;
            auto iter = v[s[0] - '0'].begin();
            while (true) {
                if (iter == v[s[0] - '0'].end() || cmp(s, *iter)) {
                    v[s[0] - '0'].insert(iter, s);
                    break;
                }
                iter++;
            }
        }
        string r;
        for (auto l=v.rbegin(); l != v.rend(); l++) {
            for (auto s: *l) {
                r.append(s);
            }
        }
        if (r.length() == 0 || r[0] == '0') {
            return "0";
        }
        return r;
    }

    static bool cmp2(const string &s1, const string &s2) {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber2(vector<int> &nums) {
        vector<string> v(nums.size());
        for (int i=0;i<nums.size();i++) {
            v[i] = to_string(nums[i]);
        }
        sort(v.begin(), v.end(), cmp2);
        if (v[0][0] == '0') {
            return "0";
        }
        string r;
        for (auto s: v) {
            r.append(s);
        }
        return r;
    }
};


int main() {
    Solution s;
    vector<int> n = {3, 30, 34, 5, 9};
    auto r = s.largestNumber(n);

    vector<int> k = {9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519};
    r = s.largestNumber(k);
    auto r2 = s.largestNumber2(k);
    auto s1 = "995998549642963295795569525905189958985890288238775871870185978591838283748308308827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014";
    auto s2 = "995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014";

    return 0;
}