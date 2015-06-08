// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return std::distance(std::begin(nums), UniqueMostTwice(std::begin(nums), std::end(nums)));
    }
    template <typename ForwardIterator>
    ForwardIterator
    UniqueMostTwice(ForwardIterator first, ForwardIterator last) {
        if (std::distance(first, last) < 3) return last;
        ForwardIterator pre = first;
        ForwardIterator cur = ++first;
        
        while (++first != last) {
            if (*pre != *first) {
                *++cur = *first;
                ++pre;
            }
        }
        return ++cur;
    }
};

