// https://leetcode.com/problems/reverse-bits/
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    int val = 0;
    for (uint32_t i = 0; n && i < 32; ++i) {
      val |= ((n & 1) << (31 - i));
      n >>= 1;
    }
    return val;
  }
};
