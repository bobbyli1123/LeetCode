// 2025-4-26
// 643. 子数组最大平均数 I <Easy> [滑动窗口]

#include "environment.h"

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = k;
        int sum = 0;
        for (int i = 0; i < k; ++i) sum += nums[i];
        double maxA = (double)sum / k;
        while (r < nums.size()) {
            sum += nums[r] - nums[l];
            maxA = max(maxA, (double)sum / k);
            ++l;
            ++r;
        }
        return maxA;
    }
};

int main() {
    return 0;
}