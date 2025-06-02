// 2025-5-30
// BM86 大数加法 <Medium> [字符串]

#include "environment.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        if (s.empty()) return t;
        else if (t.empty()) return s;
        string res;
        int p = s.length() - 1, q = t.length() - 1;
        int c = 0;
        while (p >= 0 || q >= 0) {
            int r = c;
            if (p >= 0) {
                r += s[p--] - '0';
            }
            if (q >= 0) {
                r += t[q--] - '0';
            }
            c = r / 10;
            r = r % 10;
            res.push_back(r + '0');
        }
        if (c) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
}; 