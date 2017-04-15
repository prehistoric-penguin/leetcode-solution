// https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        auto addNode = [](ListNode*& tail, int val) {
            ListNode* newNode = new ListNode(val);
            tail->next = newNode;
            tail = newNode;
        };
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                addNode(tail, l1->val);
                l1 = l1->next;
            } else {
                addNode(tail, l2->val);
                l2 = l2->next;
            }
        }
        if (l1) {
            tail->next = l1;
        }
        if (l2) {
            tail->next = l2;
        }
        return dummy.next;
    }
};
