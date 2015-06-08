// https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k %= sz;
        if (!k) return;
        auto it = std::next(nums.begin(), sz - k);
        std::reverse(nums.begin(), it);
        std::reverse(it, nums.end());
        std::reverse(nums.begin(), nums.end());        
    }
};

