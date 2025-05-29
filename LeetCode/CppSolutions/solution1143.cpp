// 2025-5-29
// 1143. 最长公共子序列 <Medium> [动态规划]

#include "environment.h"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(2, vector<int>(n + 1 , 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i & 1][j] = dp[!(i & 1)][j - 1] + 1;
                } else {
                    dp[i & 1][j] = max(dp[!(i & 1)][j], dp[i & 1][j - 1]);
                }
            }
        }
        return dp[m & 1][n];
    }
};