// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        // delete current node and point to next node
        auto delNode = [](ListNode*& node) {
            ListNode* tmp = node;
            node = node->next;
            delete tmp;
        };
        while (head != nullptr) {
            bool toDel = false;
            while (head->next != nullptr && head->val == head->next->val) {
                delNode(head);
                toDel = true;
            }
            if (toDel) {
                delNode(head);
                continue;
            }
            pre->next = head;
            pre = head;
            head = head->next;
        }
        pre->next = head;
        return dummy.next;
    }
};

