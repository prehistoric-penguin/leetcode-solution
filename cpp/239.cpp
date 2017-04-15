// https://leetcode.com/problems/sliding-window-maximum/
class MaxQueue {
 public:
  void push(int val) {
    while (!deq.empty() && deq.back() < val) {
      deq.pop_back();
    }
    deq.push_back(val);
    que.push(val);
  }
  void pop() {
    if (deq.front() == que.front()) {
      deq.pop_front();
    }
    que.pop();
  }
  int get_max() { return deq.front(); }
  std::queue<int> que;
  std::deque<int> deq;
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty() || !k || k > nums.size()) {
      return {};
    }
    int sz = nums.size();
    int i = 0;
    MaxQueue mq;
    for (i = 0; i < k; ++i) {
      mq.push(nums[i]);
    }

    std::vector<int> ans;
    ans.push_back(mq.get_max());

    for (; i < sz; ++i) {
      mq.pop();
      mq.push(nums[i]);
      ans.push_back(mq.get_max());
    }

    return ans;
  }
};
