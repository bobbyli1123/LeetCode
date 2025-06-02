// 2025-6-2
// BM30 二叉搜索树与双向链表 <Medium> [二叉树]

#include "environment.h"

using namespace std;

class Solution {
public:
    TreeNode *pre = nullptr, *head = nullptr;
    void dfs(TreeNode* curr) {
        if (curr == nullptr) return;
        dfs(curr->left);
        if (pre != nullptr) pre->right = curr;
        else head = curr;
        curr->left = pre;
        pre = curr;
        dfs(curr->right);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        dfs(pRootOfTree);
        return head;
    }
};
