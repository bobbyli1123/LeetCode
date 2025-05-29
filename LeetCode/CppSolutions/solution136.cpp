// 2025-5-29
// 136. 只出现一次的数字 <Easy> [位运算]

#include "environment.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};