// 2025-5-13
// 157 链表内指定区间反转 <Medium> [单链表]

#include "environment.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int idx = 1;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* preHead = dummy;
        ListNode* preTail = nullptr;
        while (idx <= n) {
            if (idx < m) {
                preHead = curr;
                curr = curr->next;
            } else if (idx == m) { 
                preTail = curr;
                prev = curr;
                curr = curr->next;
            } else {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            ++idx;
        }
        preHead->next = prev;
        preTail->next = curr;
        return dummy->next;
    }
};