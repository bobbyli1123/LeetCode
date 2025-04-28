// 2025-4-28
// 104. 二叉树的最大深度 <Easy> [树]

#include "environment.h"

using namespace std;

class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0; // 如果节点为空，返回深度0
        return max(dfs(root->left), dfs(root->right)) + 1; // 返回左右子树的最大深度加1
    }

    int maxDepth(TreeNode* root) {
        return dfs(root); // 调用深度优先搜索函数
    }
};