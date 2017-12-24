class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> ans;
        using pair = std::pair<std::string, const std::string*>;
        std::vector<pair> vec;
        for (const auto& s : strs) {
            std::string s1 = s;
            std::sort(std::begin(s1), std::end(s1));
            vec.emplace_back(s1, &s);
        }
        
        std::sort(std::begin(vec), std::end(vec));
        for (auto it = std::begin(vec); it != std::end(vec);) {
            auto upper = std::upper_bound(it, std::end(vec), *it,
                                         [](const pair& lhs, const pair& rhs){
                                             return lhs.first < rhs.first;
                                         });
            std::vector<std::string> tmp;
            std::transform(it, upper, std::back_inserter(tmp), [](const pair& p) {
                return *p.second;
            });
            it = upper;
            ans.emplace_back(std::move(tmp));
        }
        return ans;
    }
};
