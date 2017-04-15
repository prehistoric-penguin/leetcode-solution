// https://leetcode.com/problems/partition-list
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
    ListNode* partition(ListNode* head, int x) {
        ListNode leftHead(0);
        ListNode rightHead(0);
        ListNode* leftTail = &leftHead;
        ListNode* rightTail = &rightHead;
        
        while (head != nullptr) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = head;
            } else {
                rightTail->next = head;
                rightTail = head;
            }
            head = head->next;
        }
        rightTail->next = nullptr;
        leftTail->next = rightHead.next;
        return leftHead.next;
    }
};

