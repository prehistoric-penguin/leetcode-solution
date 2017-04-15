// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        ListNode* pre = cur;
        ++n;
        while (n-- > 0 && cur != nullptr) cur = cur->next;
        while (cur != nullptr) {
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
        
        return dummy.next;
    }
};

