// https://leetcode.com/problems/isomorphic-strings/
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    std::vector<int> vec1(s.size(), 0), vec2(s.size(), 0);
    solve(s, vec1);
    solve(t, vec2);

    return vec1 == vec2;
  }
  void solve(const std::string& s, std::vector<int>& vec) {
    std::vector<int> mp(256, -1);
    for (size_t i = 0; i < s.size(); ++i) {
      char ch = s[i];

      if (mp[ch] == -1) {
        mp[ch] = i;
        vec.push_back(i);
      } else {
        vec.push_back(mp[ch]);
      }
    }
  }
};
