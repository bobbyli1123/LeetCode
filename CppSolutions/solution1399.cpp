// 2025-4-23
// 1399. 统计最大组的数目 <Easy> []

#include "environment.h"

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        int cnt[37] {0};
        while (n) {
            int t = n, curr = 0;
            while (t) {
                curr += (t % 10);
                t /= 10;
            }
            ++cnt[curr];
            --n;
        }
        int maxC = 0, maxG = 0;
        for (int i = 1; i < 37; ++i) {
            if (cnt[i] > maxG) {
                maxG = cnt[i];
                maxC = 1;
            } else if (cnt[i] == maxG) {
                ++maxC;
            }
        }
        return maxC;
    }
};


int main() {
    return 0;
}