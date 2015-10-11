// https://leetcode.com/problems/valid-anagram/
class Solution {
 public:
  bool isAnagram(string s, string t) {
    std::sort(std::begin(s), std::end(s));
    std::sort(std::begin(t), std::end(t));

    return s == t;
  }
};
