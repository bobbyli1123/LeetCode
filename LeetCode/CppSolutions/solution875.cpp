// 2025-5-29
// 875. 爱吃香蕉的珂珂 <Medium> [二分]

#include "environment.h"

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 0, right = *ranges::max_element(piles) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int time = 0;
            for (auto p : piles) {
                time += (p + mid - 1) / mid;
            }
            if (time < h) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};