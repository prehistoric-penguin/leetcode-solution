// https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
 public:
  void reverseWords(string& s) {
    istringstream iss(s);
    std::vector<std::string> vec((istream_iterator<std::string>(iss)),
                                 istream_iterator<std::string>());
    std::reverse(std::begin(vec), std::end(vec));
    s = std::accumulate(std::begin(vec), std::end(vec), std::string(""),
                        [](const std::string& former, std::string& s) {
                          return former.empty() ? s : former + " " + s;
                        });
  }
};
