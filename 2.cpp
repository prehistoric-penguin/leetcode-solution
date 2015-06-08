// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        int carry = 0;
        auto addNode = [](ListNode* tail, int val) {
          tail->next = new ListNode(val);
        };
        while (l1 || l2) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            addNode(tail, sum);
            tail = tail->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            addNode(tail, carry);
        }
        return dummy.next;
    }
};

