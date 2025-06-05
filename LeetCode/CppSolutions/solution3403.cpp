// 2025-6-4 (daily)
// 3403. 从盒子中找出字典序最大的字符串 I <Medium> [枚举][双指针]

#include "environment.h"

using namespace std;


class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string res;
        int n = word.length() - numFriends + 1;
        for (int i = 0; i < word.length(); ++i) {
            string temp = i >= numFriends ? word.substr(i) : word.substr(i, n);
            if (res < temp) res = temp;
        }
        return res;
    }
};