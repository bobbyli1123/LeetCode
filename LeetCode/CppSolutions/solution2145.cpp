// 2025-4-21
// 2145. 统计隐藏数组数目 <Medium> [差分数组]

#include "environment.h"

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minD = INT_MAX, maxD = INT_MIN, curr = 0;
        for (int d : differences) {
            curr += d;
            minD = min(minD, curr);
            maxD = max(maxD, curr);
        }
        int ans = upper - lower - (maxD - minD) + 1;
        return ans < 0 ? 0 : ans;
    }
};

void main() {

}