// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    std::vector<int> vec(nums.size(), 1);
    for (size_t i = 1; i < nums.size(); ++i) {
      vec[i] = nums[i - 1] * vec[i - 1];
    }
    int calfromright = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      vec[i] *= calfromright;
      calfromright *= nums[i];
    }
    return vec;
  }
};
