// 2025-4-17
// 2176. 统计数组中相等且可以被整除的数对 <Easy> [哈希表]

#include "environment.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> s;
        int res = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (!s[nums[j]].empty()) {
                for (int i: s[nums[j]]) {
                    if ((i * j) % k == 0) ++res;
                }
            }
            s[nums[j]].push_back(j);
        }
        return res;
    }
};


int main() {
    return 0;
}