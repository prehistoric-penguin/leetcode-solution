// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t sz = nums1.size() + nums2.size();
        std::vector<int> result(sz, 0);
        std::merge(std::begin(nums1), std::end(nums1),
                    std::begin(nums2), std::end(nums2),
                    std::begin(result));
        return sz % 2 ? result[sz / 2] : (result[sz / 2 - 1] + result [sz / 2]) / 2.0;
    }
};

