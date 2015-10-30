// https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    void reverseWords(string &s) {
        std::istringstream iss(s);
        std::vector<std::string> vec((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());
        s = std::accumulate(vec.rbegin(), vec.rend(), std::string(""),
                            [](const std::string& former, std::string& s) {
                                return former.empty() ? s : former + " " + s;
                            });
    }
};
