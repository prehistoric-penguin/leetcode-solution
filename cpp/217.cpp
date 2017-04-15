// https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return std::unordered_set<int>(std::begin(nums), std::end(nums)).size() != nums.size();
    }
};

