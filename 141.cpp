// https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            head = head->next;
            if (fast == head) {
                return true;
            }
        }
        return false;
    }
};

