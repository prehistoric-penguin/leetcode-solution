// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    // greedy
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        // record each charcter's last meet index
        int chset[128];
        // start index of current substring
        int start = 0;
        std::fill(std::begin(chset), std::end(chset), -1);
        
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            if (chset[s[i]] >= start) {
                maxLen = std::max(maxLen, i - start);
                start = chset[s[i]] + 1;
            }
            chset[s[i]] = i;
        }
        int lastLen = s.size() - start;
        return std::max(maxLen, lastLen);
    }
};

