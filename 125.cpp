// https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(std::begin(s), std::end(s), [](char ch) { return !std::isalnum(ch);}), s.end());
        std::transform(std::begin(s), std::end(s), std::begin(s), [](char ch) { return std::tolower(ch); });
        return std::string(s.rbegin(), s.rend()) == s;
    }
};

