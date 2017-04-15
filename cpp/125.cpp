// https://leetcode.com/problems/valid-palindrome/
class Solution {
 public:
  bool isPalindrome(string s) {
    s.erase(std::remove_if(std::begin(s), std::end(s), [](char ch) {
      return !isalnum(ch);
    }), std::end(s));
    return std::equal(
        std::begin(s), std::next(std::begin(s), s.size() / 2), s.rbegin(),
        [](char lhs, char rhs) { return tolower(lhs) == tolower(rhs); });
  }
};
