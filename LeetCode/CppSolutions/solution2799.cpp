// 2025-4-24
// 2799. 统计完全子数组的数目 <Medium> [滑动窗口]

#include "environment.h"

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) ++cnt[x];
        int k = cnt.size();
        cnt.clear();
        int diff = 0, res = 0, left = 0;
        for (int x : nums) {
            if (cnt[x]++ == 0) ++diff;
            while (diff == k) {
                if (--cnt[nums[left]] == 0) --diff;
                ++left;
            }
            res += left;
        }
        return res;
    }
};

int main() {
    return 0;
}