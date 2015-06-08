// https://leetcode.com/problems/integer-to-roman/
class Solution {
public:
    string intToRoman(int num) {
        const std::string kRoman[] = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
            "V", "IV", "I"
        };
        const int kNums[] = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        };
        std::string ans;
        for (size_t i = 0; num > 0; ++i) {
            int count = num / kNums[i];
            num %= kNums[i];
            while (count-- > 0) ans += kRoman[i];
        }
        return ans;
    }
};

