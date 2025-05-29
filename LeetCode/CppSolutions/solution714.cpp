// 2025-5-29
// 714. 买卖股票的最佳时机含手续费 <Medium> [动态规划]

#include "environment.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp[2][2], n = prices.size();
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i & 1][0] = max(dp[!(i & 1)][0], dp[!(i & 1)][1] + prices[i] - fee);
            dp[i & 1][1] = max(dp[!(i & 1)][1], dp[!(i & 1)][0] - prices[i]);
        }
        return dp[!(n & 1)][0];
    }
};