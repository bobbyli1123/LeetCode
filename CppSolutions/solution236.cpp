// 2025-4-28
// 236. 二叉树的最近公共祖先 <Medium> [树]

#include "environment.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root; // 递归终止条件
        TreeNode* left = lowestCommonAncestor(root->left, p, q);   // 在左子树中查找p和q
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // 在右子树中查找p和q
        if (left && right) return root; // 如果p和q分别在左右子树中，则当前节点为最近公共祖先
        return left ? left : right; // 否则返回非空的子树节点（即p或q）
    }
};