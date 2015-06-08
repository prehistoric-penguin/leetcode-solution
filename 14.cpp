// https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int minLength = std::min_element(
                strs.begin(), strs.end(),
                [](const std::string& lhs, const std::string& rhs) {
                    return lhs.size() < rhs.size();
                }
        )->size();
        auto first = strs.begin();
        auto last = strs.end();
        std::string ans;
        for (int i = 0; i < minLength; ++i) {
            auto it = first;
            char pre = (*it++)[i];
            while (it != last && (*it)[i] == pre) ++it;
            if (it == last) {
                ans += pre;
            } else {
                break;
            }
        }
        return ans;
    }
};

