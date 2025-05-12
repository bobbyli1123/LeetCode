// 2025-4-19
// 2563. 统计公平数对的数目 <Medium> [排序][二分查找]

#include "environment.h"

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for (int j = 0; j < nums.size(); ++j) {
            res += upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]) -
                lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
        }
        return res;
    }
};

void main() {

}