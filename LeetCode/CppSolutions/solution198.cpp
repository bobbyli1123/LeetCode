// 2025-5-29
// 198. 打家劫舍 <Medium> [动态规划]

#include "environment.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int dp[2] {nums[0], max(nums[0], nums[1])};
        int n = nums.size();
        for (int i = 2; i < n; ++i) {
            dp[i & 1] = max(dp[i & 1] + nums[i], dp[!(i & 1)]);
        }
        return dp[!(n & 1)];
    }
};