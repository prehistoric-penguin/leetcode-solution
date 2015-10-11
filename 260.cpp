// https://leetcode.com/problems/single-number-iii/
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int tmp = 0;
    for (int val : nums) {
      tmp ^= val;
    }
    int bit_idx = __builtin_ctz(tmp);
    int first = 0, second = 0;
    for (int val : nums) {
      if (val & (1 << bit_idx)) {
        first ^= val;
      } else {
        second ^= val;
      }
    }
    return {first, second};
  }
};
