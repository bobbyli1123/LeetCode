// 2025-4-26
// 334. 递增的三元子序列 <Medium> [贪心]

#include "environment.h"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0], second = INT_MAX;
        for (int x : nums) {
            if (x > second) return true;
            else if (x > first) second = x;
            else first = x;
        }
        return false;
    }
};