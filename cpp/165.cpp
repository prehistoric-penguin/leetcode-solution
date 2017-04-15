// https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto splitString = [](const std::string& str) {
            int pos = 0;
            int pre = 0;
            std::vector<int> vec;
            while ((pos = str.find('.', pre)) != std::string::npos) {
                ++pos;
                vec.push_back(std::stoi(str.substr(pre, pos - pre)));
                pre = pos;
            }
            vec.push_back(std::stoi(str.substr(pre, str.size() - pre)));
            return vec;
        };

        std::vector<int> vec1 = splitString(version1);
        std::vector<int> vec2 = splitString(version2);

        int maxSize = std::max(vec1.size(), vec2.size());
        vec1.resize(maxSize);
        vec2.resize(maxSize);
        
        int mappingArray[] = {1, -1};
        return vec1 == vec2 ? 0 : mappingArray[vec1 < vec2];
    }
};
