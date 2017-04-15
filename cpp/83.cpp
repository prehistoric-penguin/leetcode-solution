// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* ans = head;
        ListNode* pre = head;
        head = head->next;
        while (head != nullptr) {
            if (pre->val == head->val) {
                pre->next = head->next;
                ListNode* toDel = head;
                head = head->next;
                delete toDel;
            } else {
                pre = pre->next;
                head = head->next;
            }
        }
        return ans;
    }
};

