// 2025-5-4
// 1128. 等价多米诺骨牌对的数量 <Medium> [数组][哈希表][数学]

#include "environment.h"

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (auto &dominoe :dominoes) {
            int key = dominoe[0] > dominoe[1] ? dominoe[1] * 10 + dominoe[0] : dominoe[0] * 10 + dominoe[1];
            ++cnt[key];
        }
        for (auto &[_, a] : cnt) {
            if (a > 1) res += a * (a - 1) / 2;
        }
        return res;
    }
};