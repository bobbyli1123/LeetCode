// 2025-4-28
// 1372. 二叉树中的最长交错路径 <Medium> [树]

#include "environment.h"

using namespace std;

class Solution {
public:
    int maxLength = 0;
    // 递归函数，参数分别为当前节点、当前节点是否是左子节点、当前路径长度
    void dfs(TreeNode* root, bool isLeft, int length) {
        if (!root) return;
        maxLength = max(maxLength, length);
        // 如果当前节点是左子节点，则递归右子节点，路径长度加1；否则递归左子节点，路径长度加1
        if (isLeft) {
            dfs(root->left, true, 1);
            dfs(root->right, false, length + 1);
        } else {
            dfs(root->left, true, length + 1);
            dfs(root->right, false, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);  // 从根节点开始，假设当前节点是左子节点，路径长度为0
        dfs(root, false, 0); // 从根节点开始，假设当前节点是右子节点，路径长度为0
        return maxLength;    // 返回最长路径长度    
    }
};