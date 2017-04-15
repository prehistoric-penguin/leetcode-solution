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
    while (head != nullptr) {
      ListNode* tmp = head->next;
      if (head->val == val) {
        pre->next = tmp;
        delete head;
        head = tmp;
      } else {
        pre = head;
        head = tmp;
      }
    }
    return dummy.next;
  }
};
