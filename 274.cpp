// https://leetcode.com/problems/h-index/
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    if (citations.empty()) {
      return 0;
    }
    std::sort(std::begin(citations), std::end(citations));
    int len = citations.size();
    for (int i : citations) {
      if (len <= i) {
        return len;
      } else {
        --len;
      }
    }
    return len;
  }
};
