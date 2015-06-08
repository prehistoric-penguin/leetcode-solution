// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> meetNum;
        
        auto genNext = [](int val) {
            int ans = 0;
            do {
                int tmp = val % 10;
                ans += tmp * tmp;
            } while (val /= 10);
            return ans;
        };
        while (n != 1 && !meetNum.count(n)) {
            meetNum.insert(n);
            n = genNext(n);
        }
        return n == 1;
    }
};
