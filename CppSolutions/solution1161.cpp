// 2025-4-28
// 1161. 最大层内元素和 <Medium> [树][BFS]

#include "environment.h"

using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        int maxSum = INT_MIN, maxLevel = 0, level = 1;
        while (!bfs.empty()) {
            int n = bfs.size(), levelSum = 0;
            while (n--) {
                TreeNode* curr = bfs.front();
                bfs.pop();
                levelSum += curr->val; // 计算当前层的元素和
                if (curr->left) bfs.push(curr->left);
                if (curr->right) bfs.push(curr->right);
            }
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }
            ++level;
        }
        return maxLevel; // 返回最大层内元素和的层数
    }
};