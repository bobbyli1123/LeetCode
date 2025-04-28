// 2025-4-28
// 841. 钥匙和房间 <Medium> [图][DFS][BFS]

#include "environment.h"

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int curr, vector<bool>& visited) {
        visited[curr] = true;
        for (int nxt : rooms[curr]) {
            if (!visited[nxt]) dfs(rooms, nxt, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, 0, visited);
        for (bool vis : visited) {
            if (!vis) return false;
        }
        return true;
    }
};