// 2025-4-28
// 2130. 链表最大孪生和 <Medium> [链表]

#include "environment.h"

using namespace std;

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values; // 存储链表节点的值
        ListNode* curr = head; // 当前节点指针
        while (curr) {
            values.push_back(curr->val); // 将节点值添加到数组中
            curr = curr->next; // 移动到下一个节点
        }
        int n = values.size(); // 链表的长度
        int maxSum = 0; // 最大孪生和
        for (int i = 0; i < n / 2; ++i) {
            maxSum = max(maxSum, values[i] + values[n - 1 - i]); // 更新最大孪生和
        }
        return maxSum; // 返回最大孪生和
    }
};