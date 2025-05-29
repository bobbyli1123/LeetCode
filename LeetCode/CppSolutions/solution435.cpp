// 2025-5-29
// 435. 无重叠区间 <Medium> [贪心]

#include "environment.h"

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        ranges::sort(intervals, [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int res = 1;

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++res;
                right = intervals[i][1];
            }
        }

        return n - res;
    }
};