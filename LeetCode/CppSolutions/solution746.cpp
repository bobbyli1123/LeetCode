// 2025-5-29
// 746. 使用最小花费爬楼梯 <Easy> [动态规划]

#include "environment.h"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2] {0, 0};
        for (int i = 2; i <= cost.size(); ++i) {
            dp[i % 2] = min(dp[i & 1] + cost[i - 2], dp[!(i & 1)] + cost[i - 1]);
        }
        return dp[cost.size() & 1];
    }
};