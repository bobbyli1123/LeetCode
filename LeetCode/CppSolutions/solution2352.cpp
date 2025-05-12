// 2025-4-27
// 2352. 相等行列对 <Medium> [哈希表]

#include "environment.h"

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> cnt; // unordered_map 不能使用 vector 作为 key
        for (const auto& row : grid) {
            cnt[row]++;
        }

        int res = 0;
        for (int j = 0; j < n; ++j) {
            vector<int> arr;
            for (int i = 0; i < n; ++i) {
                arr.push_back(grid[i][j]);
            }
            if (cnt.find(arr) != cnt.end()) {
                res += cnt[arr];
            }
        }
        return res;
    }
};