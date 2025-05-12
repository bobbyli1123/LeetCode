// 2025-5-13
// 3725 反转链表 <Easy> [单链表]

#include "environment.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        ListNode* prev = nullptr, * curr = head;
        while (curr) {
            ListNode* next = curr->next; // Store the next node
            curr->next = prev;           // Reverse the current node's pointer
            prev = curr;                // Move prev to current node
            curr = next;                // Move to the next node
        }
        return prev; // New head of the reversed list
    }
};