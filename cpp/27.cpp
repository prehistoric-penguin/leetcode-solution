// https://leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return std::distance(std::begin(nums), remove(std::begin(nums), std::end(nums), val));
    }
    template <typename ForwardIterator, typename T>
    ForwardIterator
    remove(ForwardIterator first, ForwardIterator last, const T& val) {
        if (first == last) return first;
        ForwardIterator result = first;
        for (; first != last; ++first) {
            if (*first != val) {
                *result++ = *first;
            }
        }
        return result;
    }
};

