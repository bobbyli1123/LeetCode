// 2025-5-3
// 1007. 行相等的最少多米诺旋转 <Medium> [贪心]

#include "environment.h"

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int cnt[7] {0};
        int cnt_top[7] {0};
        int cnt_bottom[7] {0};
        int n = tops.size();
        for (int i = 0; i < n; ++i) {
            ++cnt[tops[i]];
            ++cnt_top[tops[i]];
            ++cnt_bottom[bottoms[i]];
            if (tops[i] != bottoms[i]) ++cnt[bottoms[i]];
        }
        int maxNum = 0;
        for (int i = 0; i < 7; ++i) {
            if (cnt[i] > cnt[maxNum]) maxNum = i;
        }
        return cnt[maxNum] < n ? -1 : n - max(cnt_top[maxNum], cnt_bottom[maxNum]);
    }
};