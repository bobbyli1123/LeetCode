// 2025-4-28
// 450. 删除二叉搜索树中的节点 <Medium> [树][二叉搜索树]

#include "environment.h"

using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key); 
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val == key) {
            if (!root->left && !root->right) return nullptr;
            if (!root->right) return root->left;
            if (!root->left) return root->right;
            TreeNode *nxt = root->right;
            while (nxt->left) {
                nxt = nxt->left;
            }
            root->right = deleteNode(root->right, nxt->val); // 删除右子树中最小的节点
            nxt->right = root->right;
            nxt->left = root->left;
            return nxt;
        }
        return root;
    }
};  