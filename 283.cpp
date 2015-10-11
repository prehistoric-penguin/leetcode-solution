// https://leetcode.com/problems/move-zeroes/

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    std::stable_sort(std::begin(nums), std::end(nums),
                     [](int lhs, int rhs) { return rhs == 0; });
  }
};
