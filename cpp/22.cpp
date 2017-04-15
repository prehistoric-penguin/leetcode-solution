// https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
 std::vector<std::string> generateParenthesis(int n) {
        if (!n) return {};
        std::vector<std::string> ans;
        generate(0, 0, n, "", ans);
        
        return ans;
    }
    void generate(int left, int right, int n, std::string current, std::vector<std::string>& ans) {
        if (left == right && left == n) {
            ans.push_back(std::move(current));
            return;
        }
        if (left > n || right > n || left < right) return;
        generate(left + 1, right, n, current + '(', ans);
        generate(left, right + 1, n, current + ')', ans);
    }
};

