// 2025-4-28
// 1466. 重新规划路线 <Medium> [图]


#include "environment.h"

using namespace std;

class Solution {
public:
    int dfs (int curr, int parent, vector<vector<pair<int, int>>> &e) {
        int ans = 0; // 重新规划的边数
        for (auto &edge : e[curr]) {
            if (edge.first == parent) continue; // 避免回到父节点
            ans += edge.second; // 如果需要重新规划，累加
            ans += dfs(edge.first, curr, e); // 递归遍历子节点
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> e(n); // 邻接表
        for (auto &edge : connections) {
            e[edge[0]].emplace_back(edge[1], 1); // 1表示需要重新规划
            e[edge[1]].emplace_back(edge[0], 0); // 0表示不需要重新规划
        }
        return dfs(0, -1, e); // 从节点0开始遍历，父节点为-1
    }
};