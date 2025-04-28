// 2025-4-28
// 206. 反转链表 <Easy> [链表]

#include "environment.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // 记录前一个节点
        ListNode* curr = head; // 当前节点
        while (curr) {
            ListNode* nextTemp = curr->next; // 记录下一个节点
            curr->next = prev; // 将当前节点的下一个节点指向前一个节点
            prev = curr; // 更新前一个节点为当前节点
            curr = nextTemp; // 移动到下一个节点
        }
        return prev; // 返回新的头节点
    }
};
