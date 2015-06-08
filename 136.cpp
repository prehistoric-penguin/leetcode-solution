// https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(std::begin(nums), std::end(nums), 0,
                                [](int sum, int val) {
                                    return sum^val;
                                });
    }
};

