// 2025-4-27
// 283. 移动零 <Easy> [数组]

#include "environment.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (zero < n && nums[zero] != 0) {
                ++zero;
            }
            if (zero >= n) {
                break;
            }
            if (nums[i] != 0 && i > zero) {
                // 交换 nums[i] 和 nums[zero]
                nums[zero++] = nums[i];
                nums[i] = 0;
            }
        }
    }
};

int main() {

}