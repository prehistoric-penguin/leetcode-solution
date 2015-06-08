// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto itr = std::next(std::begin(nums), k  - 1);
        std::nth_element(std::begin(nums), itr, std::end(nums), std::greater<int>());
        return *itr;
    }
};

