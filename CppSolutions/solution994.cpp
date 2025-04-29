// 2025-4-29
// 994. 腐烂的橘子 <Medium> [BFS]

#include "environment.h"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        constexpr int dirs[4][2] {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> bfs;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) bfs.emplace(i, j);
            }
        }
        int len = 0;
        while (!bfs.empty()) {
            int cnt = bfs.size();
            while (cnt--) {
                auto curr = bfs.front();
                bfs.pop();
                int cx = curr.first;
                int cy = curr.second;
                for (auto dir : dirs) {
                    int nx = cx + dir[0];
                    int ny = cy + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        bfs.emplace(nx, ny);
                    }
                }
            }
            ++len;
        }
        for (auto &row : grid) {
            for (auto &cell : row) {
                if (cell == 1) return -1;
            }
        }
        return len > 0 ? len - 1 : len;
    }
};