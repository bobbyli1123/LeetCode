// 2025-5-28
// 2300. 咒语和药水的成功对数 <Medium> [二分]

#include "environment.h"

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        ranges::sort(potions);
        for (int spell : spells) {
            long long tar = (success + spell - 1) / spell;
            auto pos = ranges::lower_bound(potions, tar);
            res.emplace_back(potions.end() - pos);
        }
        return res;
    }
};