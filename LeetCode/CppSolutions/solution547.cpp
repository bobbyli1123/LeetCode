// 2025-4-28
// 547. 省份数量 <Medium> [图][DFS][BFS]

#include "environment.h"

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int curr) {
        visited[curr] = true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[curr][j] && !visited[j]) dfs(isConnected, visited, j);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinceNum = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                ++provinceNum;
            }
        }
        return provinceNum;
    }
};