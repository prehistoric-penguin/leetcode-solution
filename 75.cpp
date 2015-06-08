// https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto it = std::partition(std::begin(nums), std::end(nums), [](int i) { return i == 0; });
        std::partition(it, std::end(nums), [](int i) { return i == 1; });
    }
};

