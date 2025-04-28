// 2025-4-28
// 2095. 删除链表的中间节点 <Medium> [链表]

#include "environment.h"

using namespace std;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy; // 快慢指针
        ListNode* prev = nullptr; // 记录慢指针的前一个节点
        // 快慢指针遍历链表，找到中间节点
        while (fast) {
            prev = slow; // 记录慢指针的前一个节点
            slow = slow->next;
            fast = fast->next; // 快指针走一步
            if (fast) {
                fast = fast->next; // 快指针再走一步
            }
        }
        // 删除中间节点
        if (prev) {
            prev->next = slow->next; // 删除慢指针指向的节点
        }
        // 返回新的头节点
        return dummy->next;
    }
};