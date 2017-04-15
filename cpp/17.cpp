// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        std::vector<std::string> ans;
    init();
        combine(digits, 0, "", ans);
        return ans;
    }
  void init() {
    std::unordered_map<char, std::vector<char>> m = {
      {'2', {'a', 'b', 'c'}},
      {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}},
      {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}},
      {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}},
      {'9', {'w', 'x', 'y', 'z'}}
    };
    mapping_.swap(m);
  }
    void combine(std::string& str, int index, std::string curWord, std::vector<std::string>& ans) {
        if (index == str.size()) {
            ans.push_back(std::move(curWord));
            return;
        }
        auto& vec = mapping_[str[index++]];
        for (int i = 0; i < vec.size(); ++i) {
            combine(str, index, curWord + vec[i], ans);
        }
    }
  std::unordered_map<char, std::vector<char>> mapping_;
};

