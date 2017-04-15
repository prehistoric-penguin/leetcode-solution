// https://leetcode.com/problems/merge-k-sorted-lists/
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto comp = [](const ListNode *lhs, const ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(comp)>
        node_queue(std::begin(lists),
                   std::remove(std::begin(lists), std::end(lists), nullptr),
                   comp);

    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (!node_queue.empty()) {
      tail->next = node_queue.top();
      tail = tail->next;
      node_queue.pop();

      if (tail->next != nullptr) {
        node_queue.push(tail->next);
      }
    }
    tail->next = nullptr;
    return dummy.next;
  }
};

//----------------------------------------------------
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto comp = [](const ListNode *lhs, const ListNode *rhs) {
      return lhs->val < rhs->val;
    };
    std::multiset<ListNode *, decltype(comp)> list_set(
        std::begin(lists),
        std::remove(std::begin(lists), std::end(lists), nullptr), comp);

    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (!list_set.empty()) {
      tail->next = *list_set.begin();
      tail = tail->next;

      list_set.erase(list_set.begin());
      if (tail->next != nullptr) {
        list_set.insert(tail->next);
      }
    }
    tail->next = nullptr;
    return dummy.next;
  }
};
