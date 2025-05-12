// 2025-4-28
// 2390. 从字符串中移除星号 <Medium> [栈]

#include "environment.h"

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string res;
        for (char c : s) {
            if (c == '*' && !res.empty()) {
                res.pop_back(); // 删除最后一个字符
            } else {
                res.push_back(c); // 添加当前字符
            }
        }
        return res; // 返回处理后的字符串
    }
};