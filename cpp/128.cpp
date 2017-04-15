// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(std::begin(nums), std::end(nums));
        std::unordered_set<int> alreadyMeet;
        int maxLen = 0;
        for (int i : nums) {
            if (alreadyMeet.count(i)) continue;
            int curLen = 0;
            int tmp = i;
            while (numSet.count(--tmp)) {
                ++curLen;
                alreadyMeet.insert(tmp);
            }
            while (numSet.count(i)) {
                ++curLen;
                alreadyMeet.insert(i++);
            }
            maxLen = std::max(maxLen, curLen);
        }
        return maxLen;
    }
};

