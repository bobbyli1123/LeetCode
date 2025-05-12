// 2025-4-28 (Daily)
// 2302. 统计得分小于 K 的子数组数目 <Hard> [滑动窗口]

#include "environment.h"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int left = 0, right = 0;
        long long res = 0, sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left++];
            }
            res += right - left + 1; // 计算当前窗口的子数组数量
            // 这里的子数组数量是 (right - left + 1)，因为窗口是 [left, right]
            ++right;
        }
        return res;
    }
};