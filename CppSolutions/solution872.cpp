// 2025-4-28
// 872. 叶子相似的树 <Easy> [树]

#include "environment.h"

using namespace std;

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& leaves) {
        if (!root) return; // 如果节点为空，返回
        if (!root->left && !root->right) { // 如果是叶子节点
            leaves.push_back(root->val); // 将叶子节点的值添加到数组中
        }
        dfs(root->left, leaves); // 递归遍历左子树
        dfs(root->right, leaves); // 递归遍历右子树
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2; // 存储两个树的叶子节点值
        dfs(root1, leaves1); // 遍历第一个树的叶子节点
        dfs(root2, leaves2); // 遍历第二个树的叶子节点
        return leaves1 == leaves2; // 比较两个叶子节点值的数组是否相等
    }
};