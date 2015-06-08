// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); ++i) {
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            if (mapping.count(other) && mapping[other] > i) {
                return {i + 1, mapping[other] + 1};
            }
        }
        return {};
    }
};

