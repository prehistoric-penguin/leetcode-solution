// https://leetcode.com/problems/basic-calculator-ii/
// ugly and slow
class Solution {
 public:
  int calculate(string s) {
    s.erase(std::remove(std::begin(s), std::end(s), ' '), std::end(s));
    std::deque<int> number_stack;
    int num = 0;
    size_t sz = s.size();
    int sign = '+';

    for (size_t i = 0; i < sz;) {
      if (isdigit(s[i])) {
        num = std::stoi(&s[i]);
        while (isdigit(s[i])) {
          ++i;
        }
      }
      if (!isdigit(s[i]) || i == sz - 1) {
        int tmp = 0;
        switch (sign) {
          case '+':
            number_stack.push_back(num);
            break;
          case '-':
            number_stack.push_back(-num);
            break;
          case '*':
            tmp = number_stack.back();
            number_stack.pop_back();
            number_stack.push_back(tmp * num);
            break;
          case '/':
            tmp = number_stack.back();
            number_stack.pop_back();
            number_stack.push_back(tmp / num);
            break;
          default:
            assert(0);
            break;
        }
        sign = s[i++];
        num = 0;
      }
    }
    return std::accumulate(std::begin(number_stack), std::end(number_stack), 0);
  }
};
