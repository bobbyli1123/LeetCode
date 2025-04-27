// 2025-4-27 (Daily)
// 3392. 统计符合条件长度为 3 的子数组数目 <Easy> [模拟]

#include "environment.h"

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res = 0, n = nums.size();
        int p = 0;
        for (int p = 0; p < n - 2; ++p) {
            if (nums[p + 1] % 2 == 0 && 2 * (nums[p] + nums[p + 2]) == nums[p + 1]) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}