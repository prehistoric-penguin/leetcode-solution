class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto can_transform = [](const std::string& lhs, const std::string& rhs) {
            return std::inner_product(std::begin(lhs), std::end(lhs), std::begin(rhs), 0,
                                     std::plus<int>(), std::not_equal_to<char>()) == 1;
        };
        std::queue<std::pair<std::string, int>> queue;
        // the dict will shrink when new node reached
        std::unordered_set<std::string> dict(std::begin(wordList), std::end(wordList));
        queue.emplace(beginWord, 1);
        dict.erase(beginWord);
        
        std::string tmp;
        int steps = 0;
        while (!queue.empty()) {
            std::tie(tmp, steps) = queue.front();
            queue.pop();
            
            if (tmp == endWord) return steps;
            for (auto it = std::begin(dict); it != std::end(dict);) {
                if (can_transform(tmp, *it)) {
                    queue.emplace(*it, steps + 1);
                    it = dict.erase(it);
                } else {
                    ++it;
                }
            }
        }
        return 0;
    }
};
