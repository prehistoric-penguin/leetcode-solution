// https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        do {
            ans = ans * 10 + x % 10;
        } while (x /= 10);
        if (ans > INT_MAX || ans < INT_MIN) ans = 0;
        return ans;
    }
};

