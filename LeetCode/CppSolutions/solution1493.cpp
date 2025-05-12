// 2025-4-27
// 1493. 删掉一个元素以后全为 1 的最长子数组 <Medium> [双指针]

#include "environment.h"

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), ans = 0, zero = 0;
        while (r < n) {
            if (nums[r] == 0) {
                ++zero;
            }
            while (zero > 1) {
                if (nums[l] == 0) {
                    --zero;
                }
                ++l;
            }
            ans = max(ans, r - l);
            ++r;
        }
        return ans;
    }
};