// https://leetcode.com/problems/different-ways-to-add-parentheses/
class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    if (is_number(input)) {
      return {stoi(input)};
    }
    std::vector<int> ans;
    for (size_t i = 0; i < input.size(); ++i) {
      if (std::string("-+*").find(input[i]) != std::string::npos) {
        std::vector<int> left = diffWaysToCompute(input.substr(0, i));
        std::vector<int> right =
            diffWaysToCompute(input.substr(i + 1, input.size() - i));

        for (int lvalue : left) {
          for (int rvalue : right) {
            ans.push_back(calc(lvalue, rvalue, input[i]));
          }
        }
      }
    }
    return ans;
  }
  int calc(int left, int right, char ch) {
    int ans = 0;
    switch (ch) {
      case '-':
        ans = left - right;
        break;
      case '+':
        ans = left + right;
        break;
      case '*':
        ans = left * right;
        break;
      default:
        assert(0);
        break;
    }
    return ans;
  }
  bool is_number(const std::string& str) {
    return all_of(std::begin(str), std::end(str),
                  [](char ch) { return isdigit(ch); });
  }
};
