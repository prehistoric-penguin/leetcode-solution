// https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    // do not to deal with overflow here
    // for reverse integer that overflows will never be palindromes
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int oldx = x;
        int ans = 0;
        do {
            ans = ans * 10 + x % 10;
        } while (x /= 10);
        
        return oldx == ans;
    }
};

