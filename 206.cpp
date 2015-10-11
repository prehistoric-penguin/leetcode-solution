// https://leetcode.com/problems/reverse-linked-list/
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
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode* pre = nullptr;
    while (head != nullptr) {
      ListNode* tmp = head->next;
      head->next = pre;
      pre = head;
      head = tmp;
    }
    return pre;
  }
};
