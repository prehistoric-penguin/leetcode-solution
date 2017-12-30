class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> ans;
        std::unordered_map<int, int> counter;
        for (auto v : nums) counter[v]++;
        auto cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
            return lhs.second > rhs.second;  
        };
        std::multiset<std::pair<int, int>, decltype(cmp)>
            freq(std::begin(counter), std::end(counter), cmp);
        for (auto it = std::begin(freq); k--; ++it) {
            ans.emplace_back(it->first);
        }
        return ans;
    }
};
