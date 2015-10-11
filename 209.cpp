// https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    std::vector<int> vec(nums.size(), 0);
    std::partial_sum(std::begin(nums), std::end(nums), std::begin(vec));
    int ans = INT_MAX;
    if (s < 0 || nums.empty() || s > vec.back()) {
      return 0;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      int to_find = s + (i ? vec[i - 1] : 0);

      auto first = std::next(std::begin(vec), i);
      auto it = std::lower_bound(first, std::end(vec), to_find);
      if (it != std::end(vec)) {
        ans = std::min(ans, static_cast<int>(std::distance(first, it) + 1));
      }
    }
    return ans;
  }
};
