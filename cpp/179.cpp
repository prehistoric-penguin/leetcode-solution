// https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int lhs, int rhs) {
            std::string lhsStr = std::to_string(lhs);
            std::string rhsStr = std::to_string(rhs);
            return lhsStr + rhsStr > rhsStr + lhsStr;
        });
        if (!nums.empty() && nums.front() == 0) return "0";
        return std::accumulate(nums.begin(), nums.end(), std::string(""), [](std::string& sum, int curNum) {
            return sum + std::to_string(curNum);
        });
    }
};
