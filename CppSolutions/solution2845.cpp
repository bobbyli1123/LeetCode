// 2025-4-25
// 2845. 统计趣味子数组的数目 <Nedium> [前缀和]

#include "environment.h"

using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (nums[i] % modulo == k);
        }

        vector<int> cnt(min(n + 1, modulo));
        long long ans = 0;
        for (int s : sum) {
            if (s >= k) {
                ans += cnt[(s - k) % modulo];
            }
            cnt[s % modulo]++;
        }
        return ans;
    }
};

int main() {
    return 0;
}