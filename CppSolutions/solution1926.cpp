// 2025-4-29
// 1926. 迷宫中离入口最近的出口 <Medium> [图][BFS]

#include "environment.h"

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        constexpr int dirs[4][2] {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> bfs;
        bfs.emplace(entrance[0], entrance[1]);
        int len = 0;
        while (!bfs.empty()) {
            int n = bfs.size();
            while (n--) {
                auto curr = bfs.front();
                bfs.pop();
                int cx = curr.first;
                int cy = curr.second;
                maze[cx][cy] = '+';
                if ((cx == 0 || cx == m - 1 || cy == 0 || cy == n - 1) && len > 0) return len;
                for (auto dir : dirs) {
                    int nx = cx + dir[0];
                    int ny = cy + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        bfs.emplace(nx, ny);
                    }
                }
            }
            ++len;
        }
        return -1;
    }
};