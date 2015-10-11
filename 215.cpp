// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
 public:
  template <typename Iterator, typename Compare>
  void partition(Iterator left, Iterator first, Iterator last,
                 const Compare& comp, int k) {
    if (std::distance(left, first) >= k || first == last) {
      return;
    }
    int pivot = *std::next(first, std::distance(first, last) / 2);
    Iterator it1 = std::partition(
        first, last, [pivot, &comp](int val) { return comp(val, pivot); });
    Iterator it2 = std::partition(
        it1, last, [pivot, &comp](int val) { return !comp(pivot, val); });

    partition(left, first, it1, comp, k);
    partition(left, it2, last, comp, k);
  }

  int findKthLargest(vector<int>& nums, int k) {
    partition(std::begin(nums), std::begin(nums), std::end(nums),
              std::greater<int>(), k);

    return nums[k - 1];
  }
};
//-------------------------------------------
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    auto it = std::next(std::begin(nums), k - 1);
    nth_element(std::begin(nums), it, std::end(nums), std::greater<int>());

    return *it;
  }
};
