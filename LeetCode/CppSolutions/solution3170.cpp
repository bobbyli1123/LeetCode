// 2025-6-7 (daily)
// 3170. 删除星号以后字典序最小的字符串 <Medium> [字符串]

#include "environment.h"

using namespace std;

class Solution {
public:
    string clearStars(string s) {
        string res;
        vector<vector<int>> pos(26);
        char minChar = 'a';
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c != '*') {
                pos[c - 'a'].push_back(i);
                if (c < minChar) minChar = c;
            } else {
                while (minChar != 'z' && pos[minChar - 'a'].empty()) ++minChar;
                if (!pos[minChar - 'a'].empty()) {
                    s[pos[minChar - 'a'].back()] = '*';
                    pos[minChar - 'a'].pop_back();
                }
            }
        }
        for (char c : s) {
            if (c != '*') res.push_back(c);
        }
        return res;
    }
};