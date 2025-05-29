// 2025-5-29
// 1137. 第 N 个泰波那契数 <Easy> [动态规划]

#include "environment.h"

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int dp[4] {0, 1, 1, 2};
        for (int i = 4; i <= n; ++i) {
            dp[i % 4] = dp[(i + 1) % 4] + dp[(i + 2) % 4] + dp[(i + 3) % 4];
        }
        return dp[n % 4];
    }
};