// 2025-4-28
// 437. 路径总和 III <Medium> [树]

#include "environment.h"

using namespace std;

class Solution {
public:
    int pathNum;
    void dfs(TreeNode* root, vector<int> &path, int targetSum) {
        if (!root) return;
        path.push_back(root->val);
        long long sum = 0;
        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == targetSum) ++pathNum;
        }
        dfs(root->left, path, targetSum);
        dfs(root->right, path, targetSum);
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        pathNum = 0;
        vector<int> path;
        dfs(root, path, targetSum);
        return pathNum;
    }
};