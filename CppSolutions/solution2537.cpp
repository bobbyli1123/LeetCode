// 2024-4-16
// 2537. 统计好子数组的数目 <Medium> [滑动窗口][哈希表]

#include "environment.h"

using namespace std;

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        long long pairs = 0, ans = 0;
        int left = 0;
        for (int x : nums) {
            pairs += cnt[x]++;
            while (pairs >= k) {
                pairs -= --cnt[nums[left]];
                left++;
            }
            ans += left;
        }
        return ans;
    }
};

int main()
{
    return 0;
}