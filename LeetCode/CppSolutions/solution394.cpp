// 2025-4-28
// 394. 字符串解码 <Medium> [栈]

#include "environment.h"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int k = 0;
        vector<string> str;
        vector<int> num;
        string res;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + c - '0';
            } else if (islower(c)) {
                res.push_back(c);
            } else if (c == '[') {
                num.push_back(k); 
                k = 0; 
                str.push_back(res); // 保存当前res  
                res = "";
            } else {
                int times = num.back();
                num.pop_back();
                while (times--) str.back() += res;
                res = str.back();
                str.pop_back();
            }
        }
        return res;
    }
};