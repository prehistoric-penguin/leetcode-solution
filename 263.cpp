// https://leetcode.com/problems/ugly-number/
class Solution {
 public:
  bool isUgly(int num) {
    auto div = [](int& val, int to_div) {
      while (val && val % to_div == 0) {
        val /= to_div;
      }
    };
    div(num, 2);
    div(num, 3);
    div(num, 5);
    return num == 1;
  }
};
