// 2025-4-27
// 238. 除自身以外数组的乘积 <Medium> [数组]

#include "environment.h"

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int r = 1;  // 右侧乘积
        for (int i = n - 2; i >= 0; --i) {
            r *= nums[i + 1];
            res[i] *= r;
        }
        return res;
    }
};

int main() {
    return 0;
}