// 2025-4-26
// 1004. 最大连续1的个数 III <Medium> [滑动窗口]

#include "environment.h"

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lsum = 0, rsum = 0, left = 0;
        int res = 0;
        for (int right = 0; right < nums.size(); ++right) {
            rsum += 1 - nums[right];
            while (rsum - lsum > k) {
                lsum += 1 - nums[left++];
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main() {
    return 0;
}
