// 2025-4-28
// 328. 奇偶链表 <Medium> [链表]

#include "environment.h"

using namespace std;    

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head; // 如果链表为空或只有一个节点，直接返回
        }
        ListNode* odd = head; // 奇数节点的头指针
        ListNode* even = head->next; // 偶数节点的头指针
        ListNode* evenHead = even; // 记录偶数节点的头指针
        // 遍历链表，将奇数节点和偶数节点分开
        while (even && even->next) {
            odd->next = even->next; // 将奇数节点的下一个节点指向下一个奇数节点
            odd = odd->next; // 移动奇数节点指针
            even->next = odd->next; // 将偶数节点的下一个节点指向下一个偶数节点
            even = even->next; // 移动偶数节点指针
        }
        odd->next = evenHead; // 将奇数节点的最后一个节点指向偶数节点的头指针
        return head; // 返回新的头节点
    }
};