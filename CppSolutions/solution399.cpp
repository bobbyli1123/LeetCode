// 2025-4-29
// 399. 除法求值 <Medium> [图][深度优先搜索]

#include "environment.h"

using namespace std;

class Solution {
public:
    double dfs(string curr, string tar, map<string, map<string, double>>& graph, double res, unordered_set<string>& vis) {
        if (!graph.count(curr) || !graph.count(tar)) return -1.0;
        if (curr == tar) return res;
        vis.insert(curr);
        for (auto &[nxt, value] : graph[curr]) {
            if (!vis.count(nxt)) {
                double temp = dfs(nxt, tar, graph, res * value, vis);
                if (temp > 0) return temp;
            } 
        }
        vis.erase(curr);
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, map<string, double>> graph;
        for (int i = 0; i < values.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            graph[a][b] = values[i];
            graph[b][a] = 1.0 / values[i];
        }
        unordered_set<string> vis;
        vector<double> res;
        for (auto &q : queries) {
            res.emplace_back(dfs(q[0], q[1], graph, 1.0, vis));
            vis.clear();
        }
        return res;
    }
};