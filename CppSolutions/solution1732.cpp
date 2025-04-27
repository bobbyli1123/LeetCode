// 2025-4-27
// 1732. 找到最高海拔 <Easy> [前缀和]

#include "environment.h"

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int elevation = 0, maxElevation = 0;
        for (int x : gain) {
            elevation += x;
            maxElevation = max(maxElevation, elevation);
        }
        return maxElevation;
    }
};