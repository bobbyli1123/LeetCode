// 2025-6-5
// BM11 链表相加(二) <Medium> [链表]

#include "environment.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */

    ListNode* rev(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        head1 = rev(head1); head2 = rev(head2);
        ListNode *dummy = new ListNode(0), *p = dummy;
        int c = 0;
        while (head1 != nullptr || head2 != nullptr) {
            int s = c;
            if (head1 != nullptr) {
                s += (head1->val);
                head1 = head1->next;
            }
            if (head2 != nullptr) {
                s += (head2->val);
                head2 = head2->next;
            }
            c = s / 10;
            s = s % 10;
            p->next = new ListNode(s);
            p = p->next;
        }
        if (c != 0) {
            p->next = new ListNode(c);
        }
        return rev(dummy->next);
    }
};
