// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> mapping = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        char pre = s[0];
        int sum = mapping[pre];
        for (int i = 1, sz = s.size(); i < sz; ++i) {
            int valCur = mapping[s[i]];
            int valPre = mapping[pre];
            sum += valCur;
            if (valCur > valPre) {
                sum -= (valPre * 2);
            }
            pre = s[i];
        }
        return sum;
    }
};

