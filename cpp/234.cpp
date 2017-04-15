// https://leetcode.com/problems/palindrome-linked-list/
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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode* right_tail = slow->next;
    slow->next = nullptr;
    ListNode* right = reverse_list(right_tail);
    // watch out for even odd length
    while (right != nullptr && head->val == right->val) {
      head = head->next;
      right = right->next;
    }

    return right == nullptr;
  }
  ListNode* reverse_list(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* tmp = nullptr;

    while (head != nullptr) {
      tmp = head->next;
      head->next = pre;
      pre = head;
      head = tmp;
    }
    return pre;
  }
};
