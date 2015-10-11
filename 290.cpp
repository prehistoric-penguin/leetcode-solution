// https://leetcode.com/problems/word-pattern
class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    std::vector<std::string> vec = split(str);
    std::map<std::string, char> record;
    std::map<char, std::string> reverse_record;
    if (pattern.size() != vec.size()) {
      return false;
    }
    for (size_t i = 0; i < vec.size(); ++i) {
      const auto& s = vec[i];
      char ch = pattern[i];
      auto it = record.find(s);
      if (it == record.end()) {
        if (reverse_record.count(ch)) {
          return false;
        }
        reverse_record.insert({ch, s});
        record.insert({s, ch});
      } else if (it->second != ch) {
        return false;
      }
    }
    return true;
  }
  std::vector<std::string> split(std::string& str) {
    istringstream oss(str);
    return std::vector<std::string>((istream_iterator<std::string>(oss)),
                                    istream_iterator<std::string>());
  }
};
