// 2025-4-29 (Daily)
// 2962. 统计最大元素出现至少 K 次的子数组 <Medium> [数组][滑动窗口]

#include "environment.h"

using namespace std;


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElm = *max_element(nums.begin(), nums.end());
        int maxCnt = 0, left = 0;
        long long res = 0;
        for (int x : nums) {
            if (x == maxElm) ++maxCnt;
            while (maxCnt >= k) {
                if (nums[left++] == maxElm) --maxCnt;
            }
            res += left;
        }
        return res;
    }
};