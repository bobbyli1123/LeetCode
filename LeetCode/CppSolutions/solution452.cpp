// 2025-5-29
// 452. 用最少数量的箭引爆气球 <Medium> [贪心]

#include "environment.h"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ranges::sort(points, [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });

        int curr = points[0][1];
        int res = 1;
        int n = points.size();
        
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > curr) {
                ++res;
                curr = points[i][1];
            }
        }
        
        return res;
    }
};