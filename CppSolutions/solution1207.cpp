// 2025-4-27
// 1207. 独一无二的出现次数 <Medium> [哈希表]

#include "environment.h"

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int x : arr) {
            count[x]++;
        }
        unordered_set<int> seen;
        for (const auto& [_, c] : count) {
            if (seen.count(c)) {
                return false;
            }
            seen.insert(c);
        }
        return true;
    }
};