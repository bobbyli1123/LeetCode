// 2025-5-29
// 338. 比特位计数 <Easy> [位运算][动态规划]

#include "environment.h"

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = (i & 1) + res[i >> 1];
        }
        return res;
    }
};