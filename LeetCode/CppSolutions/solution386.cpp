// 2025-6-8 (daily)
// 386. 字典序排数 <Medium> [DFS]

#include "environment.h"
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int curr = 1, base = 0;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                ++curr;
            }
        }
        return res;
    }
};