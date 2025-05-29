// 2025-5-29
// BM84 最长公共前缀 <Easy> [字符串]

#include "environment.h"

using namespace std;

class Solution {
public:
    string getPref(string &s, string &t) {
        string pref;
        int k = min(s.length(), t.length());
        for (int i = 0; i < k && s[i] == t[i]; ++i) {
            pref.push_back(s[i]);
        }
        return pref;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            res = getPref(res, strs[i]);
        }
        return res;
    }
};