// https://leetcode.com/problems/3sum/
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(std::begin(nums), std::end(nums));
        if (nums.empty() || nums.front() > 0 || nums.back() < 0) return {};

        int sz = nums.size();
        for (int i = 0; i < sz - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = sz - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (!sum) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    --k;
                    int pre = nums[j++];
                    while (j < k && nums[j] == pre)
                        ++j;
                } else if (sum < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return ans;
    }
};

