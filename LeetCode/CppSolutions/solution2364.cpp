// 2025-4-18
// 2364. 统计坏数对的数目 <Medium> [哈希表]

#include "environment.h"

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // bad: j - i != nums[j] - nums[i] -> nums[j] - j != nums[i] - i
        unordered_map<int, int> cnt;
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] -= i;
            res += i - cnt[nums[i]]++;
        }
        return res;
    }
};

void main() {

}