// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* pre = &dummy;
        while (pre != nullptr && head != nullptr) {
            if (head->val == val) {
                pre->next = head->next;
                delete head;
                head = pre->next;
            } else {
                pre = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};
