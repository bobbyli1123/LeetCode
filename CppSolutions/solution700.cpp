// 2025-4-28
// 700. 二叉搜索树中的搜索 <Easy> [树][二叉搜索树]

#include "environment.h"

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        else if (root->val < val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }
};