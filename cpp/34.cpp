// https://leetcode.com/problems/search-for-a-range/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itpair = std::equal_range(std::begin(nums), std::end(nums), target);
        if (itpair.first == std::end(nums) || *itpair.first != target) return {-1, -1};
        return {std::distance(std::begin(nums), itpair.first),
                std::distance(std::begin(nums), std::prev(itpair.second)) };
    }
};

