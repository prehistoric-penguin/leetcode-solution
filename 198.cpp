// https://leetcode.com/problems/house-robber/
class Solution {
 public:
  int rob(vector<int>& nums) {
    std::vector<int> ans(nums.size(), 0);
    size_t sz = nums.size();
    if (sz == 0) {
      return 0;
    }
    if (sz == 1) {
      return nums[0];
    }
    ans[0] = nums[0];
    ans[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < sz; ++i) {
      ans[i] = std::max(ans[i - 1], nums[i] + ans[i - 2]);
    }
    return ans[sz - 1];
  }
};
