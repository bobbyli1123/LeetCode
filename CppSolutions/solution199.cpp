// 2025-4-28
// 199. 二叉树的右视图 <Medium> [树]

#include "environment.h"

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int n = bfs.size();
            while (n--) {
                TreeNode* curr = bfs.front();
                bfs.pop();
                if (n == 0) res.push_back(curr->val);
                if (curr->left) bfs.push(curr->left);
                if (curr->right) bfs.push(curr->right);
            }
        }
        return res;
    }
};