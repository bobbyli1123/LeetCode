// 2025-5-5
// 790. 多米诺和托米诺平铺 <Medium> [动态规划]

#include "environment.h"

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        long long dp[3][3] {{0, 0, 0}, {0, 0, 0}, {1, 0, 0}};
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int idx = i % 3;
            dp[idx][0] = (dp[(idx + 2) % 3][0] + dp[(idx + 2) % 3][1] + dp[(idx + 2) % 3][2] + dp[(idx + 1) % 3][0]) % MOD;
            dp[idx][1] = (dp[(idx + 1) % 3][0] + dp[(idx + 2) % 3][2]) % MOD;
            dp[idx][2] = (dp[(idx + 1) % 3][0] + dp[(idx + 2) % 3][1]) % MOD;
            // dp[x][0] 代表 "I" 型, dp[x][1] 代表 "r" 型, dp[x][2] 代表 "L" 型。
        }
        return dp[(n - 1) % 3][0];
    }
};