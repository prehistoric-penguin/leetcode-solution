// https://leetcode.com/problems/summary-ranges/
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    int pre = nums[0];
    int first = pre;
    std::vector<std::string> ans;
    auto add_ans = [this, &ans, &pre, &first]() {
      if (pre == first) {
        ans.push_back(build_vec({pre}));
      } else {
        ans.push_back(build_vec({first, pre}));
      }
    };
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == pre + 1) {
        pre = nums[i];
      } else {
        add_ans();
        pre = first = nums[i];
      }
    }
    add_ans();
    return ans;
  }
  std::string build_vec(const std::vector<int>& vec) {
    return std::accumulate(std::begin(vec), std::end(vec), std::string(""),
                           [](const std::string& s, int val) {
                             if (s.empty()) {
                               return std::to_string(val);
                             } else {
                               return s + "->" + std::to_string(val);
                             }
                           });
  }
};
