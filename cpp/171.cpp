// https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string s) {
        int sz = s.size();
        if (!sz) return 0;
        auto charToNum = [](char ch) { return ch - 'A' + 1; };
        return sz == 1 ? charToNum(s[0]) :
                        titleToNumber(s.substr(0, sz - 1)) * 26 + charToNum(s[sz - 1]);
    }
};
