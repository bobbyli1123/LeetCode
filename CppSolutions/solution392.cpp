// 2025-4-26
// 392. 判断子序列 <Easy> [双指针]

#include "environment.h"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return false;
        
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        
        return i == m;
    }
};