// https://leetcode.com/problems/longest-common-prefix/
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    std::string ans;
    if (strs.empty()) {
      return "";
    }
    int min_len =
        min_element(std::begin(strs), std::end(strs),
                    [](const std::string& lhs, const std::string& rhs) {
                      return lhs.size() < rhs.size();
                    })->size();
    for (int i = 0; i < min_len; ++i) {
      char ch = strs[0][i];
      if (all_of(std::begin(strs), std::end(strs),
                 [ch, i](const std::string& s) { return s[i] == ch; })) {
        ans += ch;
      } else {
        break;
      }
    }
    return ans;
  }
};
