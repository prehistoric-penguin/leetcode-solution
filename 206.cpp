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
    // iteration solution
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* pre = nullptr;
        do {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        } while (head != nullptr);
        
        return pre;
    }
};

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
        return reverseList(nullptr, head);
    }
    ListNode* reverseList(ListNode* pre, ListNode* cur) {
        if (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            return reverseList(cur, tmp);
        }
        return pre;
    }
};

