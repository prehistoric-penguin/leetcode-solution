// https://leetcode.com/problems/rotate-array/
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int sz = nums.size();
    k %= sz;

    auto it = std::next(std::begin(nums), sz - k);
    std::reverse(std::begin(nums), it);
    std::reverse(it, std::end(nums));
    std::reverse(std::begin(nums), std::end(nums));
  }
};
