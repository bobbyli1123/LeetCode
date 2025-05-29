// 2025-5-29
// 17. 电话号码的字母组合 [DFS]

#include "environment.h"

using namespace std;

class Solution {
public:
    void dfs(string &digits, int curr, string &temp, vector<string> &cast, vector<string> &res) {
        if (curr == digits.length()) res.push_back(temp);
        else {
            string list = cast[digits[curr] - '0'];
            for (char c : list) {
                temp.push_back(c);
                dfs(digits, curr + 1, temp, cast, res);
                temp.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> cast {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string temp;
        if (digits.empty()) return {};
        dfs(digits, 0, temp, cast, res);
        return res;
    }
};