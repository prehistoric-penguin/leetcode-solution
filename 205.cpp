// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
bool isIsomorphic(string s, string t) {
        std::map<char, std::set<int>> charIndexVec1;
        std::map<char, std::set<int>> charIndexVec2;

        for (size_t i = 0; i < s.size(); ++i) {
            charIndexVec1[s[i]].insert(i);
        }
        for (size_t j = 0; j < t.size(); ++j) {
            charIndexVec2[t[j]].insert(j);
        }
        std::multiset<std::vector<int>> set1;
        std::multiset<std::vector<int>> set2;
        std::transform(std::begin(charIndexVec1), std::end(charIndexVec1),
                        std::inserter(set1, set1.begin()),
                        [](const std::pair<char, std::set<int>>& node) {
                            return std::vector<int>(std::begin(node.second), std::end(node.second));
                        });
        std::transform(std::begin(charIndexVec2), std::end(charIndexVec2),
                        std::inserter(set2, set2.begin()), 
                        [](const std::pair<char, std::set<int>>& node) {
                            return std::vector<int>(std::begin(node.second), std::end(node.second));
                        });
        return set1 == set2;
    }
};
