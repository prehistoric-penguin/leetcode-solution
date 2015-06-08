// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return std::distance(std::begin(nums), unique(std::begin(nums), std::end(nums)));
    }
    template <typename ForwardIterator>
    ForwardIterator
    unique(ForwardIterator _first, ForwardIterator _last) {
        if (_first == _last) return _first;
        
        ForwardIterator cur = _first++;
        for (; _first != _last; ++_first) {
            if (*cur != *_first) {
                *++cur = *_first;
            }
        }
        return ++cur;
    }
};

