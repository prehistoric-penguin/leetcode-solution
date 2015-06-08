// https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto itpair = std::equal_range(std::begin(nums), std::end(nums), target);
        if (itpair.first == std::end(nums) || *itpair.first == target) {
            return std::distance(std::begin(nums), itpair.first);
        } else {
            return std::distance(std::begin(nums), itpair.second);
        }
    }
};

