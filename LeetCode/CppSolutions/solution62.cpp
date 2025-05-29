// 2025-5-29
// 62. 不同路径 <Medium> []

#include "environment.h"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n];
        for (int j = 0; j < n; ++j) dp[j] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; 
            }
        }
        return dp[n - 1];
    }
};