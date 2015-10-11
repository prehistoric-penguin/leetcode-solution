// https://leetcode.com/problems/basic-calculator/
class Solution {
 public:
  int calculate(string s) {
    int part_sum = 0;
    int sign = 1;
    int num = 0;
    std::stack<int> nums, ops;

    for (char ch : s) {
      if (isdigit(ch)) {
        num = num * 10 + ch - '0';
      } else {
        part_sum += sign * num;
        num = 0;
        switch (ch) {
          case '+':
            sign = 1;
            break;
          case '-':
            sign = -1;
            break;
          case '(':
            nums.push(part_sum);
            ops.push(sign);
            part_sum = 0;
            sign = 1;
            break;
          case ')':
            if (!ops.empty()) {
              part_sum = part_sum * ops.top() + nums.top();
              ops.pop();
              nums.pop();
            }
        }
      }
    }
    return part_sum + sign * num;
  }
};
