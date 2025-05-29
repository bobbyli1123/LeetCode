// 2025-5-29
// 216. 组合总和 III <Medium> [DFS]

#include "environment.h"

using namespace std;

class Solution {
public:
    void dfs(int k, int n, vector<int> &temp, vector<vector<int>> &res) {
        if (k * 9 < n) return;
        if (k == 0 && n == 0) {
            res.push_back(temp);
            return;
        } else if (k == 0 || n == 0) return;
        int i = temp.empty() ? 1 : temp.back() + 1;
        while (i <= min(n, 9)) {
            temp.push_back(i);
            dfs(k - 1, n - i, temp, res);
            temp.pop_back();
            ++i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        dfs(k, n, temp, res);
        return res;
    }
};