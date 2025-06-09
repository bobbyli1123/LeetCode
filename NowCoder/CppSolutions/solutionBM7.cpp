// 2025-6-5
// BM7 链表中环的入口结点 <Medium> [链表]

#include "environment.h"

using namespace std;

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) return pHead;
        ListNode *dummy = new ListNode(0);
        dummy->next = pHead;
        ListNode *fast = pHead->next, *slow = pHead;
        while (fast != nullptr && fast != slow) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) fast = fast->next;
        } 
        if (fast == nullptr) return nullptr;
        slow = dummy;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};