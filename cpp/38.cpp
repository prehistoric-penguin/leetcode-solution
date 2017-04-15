// https://leetcode.com/problems/count-and-say/
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        std::string ans("1");
        while (--n > 0) ans = doCountAndSay(ans);
        return ans;
    }
    std::string doCountAndSay(std::string s) {
        std::string ans;
        for (auto i = s.begin(); i != s.end(); ) {
            auto it = std::find_if(i, s.end(), [&i](char ch) { return *i != ch; });
            ans += std::to_string(std::distance(i, it)) + *i;
            i = it;
        }
        return ans;
    }
};

