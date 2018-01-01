class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::sort(std::begin(nums), std::end(nums));
        size_t num_cnt = nums.size();
        size_t ans_cnt = pow(2.0, num_cnt);
        std::vector<std::vector<int>> ans(ans_cnt);
        for (size_t i = 0;i < num_cnt; ++i) {
            for (size_t j = 0; j < ans_cnt; ++j) {
                if ((j >> i) & 1) {
                    ans[j].emplace_back(nums[i]);
                }
            }
        }
        return ans;
    }
};
