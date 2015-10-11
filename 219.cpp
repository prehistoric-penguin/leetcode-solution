// https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int sz = nums.size();
    if (!k || sz == 1) return false;

    if (sz <= k) k = sz - 1;
    // build window
    std::unordered_set<int> intSet(std::begin(nums),
                                   std::next(std::begin(nums), k));
    for (int i = k; i < sz; ++i) {
      intSet.insert(nums[i]);
      if (intSet.size() < k + 1) return true;
      intSet.erase(nums[i - k]);
    }
    return false;
  }
};
