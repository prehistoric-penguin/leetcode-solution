// https://leetcode.com/problems/missing-number/
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int sz = nums.size();
    int ans = sz;
    for (int i = 0; i < sz; ++i) {
      ans ^= i;
      ans ^= nums[i];
    }

    return ans;
  }
};
