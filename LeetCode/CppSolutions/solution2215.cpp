// 2025-4-27
// 2215. 找出两数组的不同 <Easy> [哈希表]

#include "environment.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        for (int x : s1) {
            if (!s2.count(x)) {
                res[0].push_back(x);
            }
        }
        for (int x : s2) {
            if (!s1.count(x)) {
                res[1].push_back(x);
            }
        }
        return res;
    }
};