// https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        dummy.next = nullptr;
        ListNode* tail = &dummy;
        std::vector<ListNode*> listVec = lists;
        // remove null pointers
        listVec.erase(std::remove(std::begin(listVec), std::end(listVec), nullptr), std::end(listVec));
        auto ListNodeCompare = [](const ListNode* lhs, const ListNode* rhs) {
          return lhs->val < rhs->val;  
        };
        auto tailInsert = [&tail](int val) {
            tail->next = new ListNode(val);
            tail = tail->next;
            tail->next = nullptr;
        };
        std::multiset<ListNode*, decltype(ListNodeCompare)> listSet(std::begin(listVec), std::end(listVec),
                                                                ListNodeCompare);
        
        while (!listSet.empty()) {
            ListNode* ptr = *listSet.begin();
            tailInsert(ptr->val);
            listSet.erase(listSet.begin());
            if (ptr->next != nullptr) {
                listSet.insert(ptr->next);
            }
        }
        return dummy.next;
    }
};

