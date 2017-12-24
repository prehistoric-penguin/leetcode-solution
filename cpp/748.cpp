class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        if (words.empty()) return {};
        std::unordered_map<char, size_t> mem;
        auto process = [](const std::string& s, std::unordered_map<char, size_t>* dict) {
            for (auto ch : s) {
                if (isalpha(ch)) {
                    (*dict)[std::tolower(ch)]++;
                }
            }
        };
        process(licensePlate, &mem);
        using pair = std::pair<std::string, size_t>;
        std::vector<pair> candidate;
        
        for (size_t i = 0; i < words.size(); ++i) {
            const auto& w = words[i];
            std::unordered_map<char, size_t> tmp;
            process(w, &tmp);
            bool ok = true;
            for (auto& p : mem) {
                if (tmp[p.first] < p.second) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                candidate.emplace_back(w, i);
            }
        }
        return std::min_element(std::begin(candidate), std::end(candidate),
                                [](const pair& lhs, const pair& rhs) {
                    return lhs.first.length() != rhs.first.length()
                        ? lhs.first.length() < rhs.first.length()
                        : lhs.second < rhs.second;
                })->first;
    }
};
