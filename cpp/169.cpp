// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto it = std::next(nums.begin(), nums.size() / 2);
        std::nth_element(nums.begin(), it, nums.end());
        return *it;
    }
};
