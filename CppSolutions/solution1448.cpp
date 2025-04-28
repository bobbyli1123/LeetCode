// 2025-4-28
// 1448. 统计二叉树中好节点的数目 <Medium> [树]

#include "environment.h"

using namespace std;

class Solution {
public:
    int goodNum;
    void dfs(TreeNode *root, int maxValue) {
        if (!root) return;
        if (root->val >= maxValue) {
            ++goodNum;
            maxValue = root->val;
        }
        dfs(root->left, maxValue);
        dfs(root->right, maxValue);
    }
    int goodNodes(TreeNode* root) {
        goodNum = 0;
        dfs(root, root->val);
        return goodNum;
    }
};