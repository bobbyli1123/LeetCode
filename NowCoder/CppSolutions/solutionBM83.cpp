// 2025-5-29
// BM83 字符串变形 <Easy> [字符串]

#include "environment.h"

using namespace std;

class Solution {
public:
    string trans(string s, int n) {
        // write code here
        reverse(s.begin(), s.end());
        string res, temp;
        for (char c : s) {
            if (isalpha(c)) {
                temp.push_back(c >= 'a' ? c - 32 : c + 32);
            } else {
                reverse(temp.begin(), temp.end());
                temp.push_back(' ');
                res += temp;
                temp.clear();
            }
        }
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            res += temp;
        }
        return res;
    }
};