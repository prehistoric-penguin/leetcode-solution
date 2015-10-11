// https://leetcode.com/problems/happy-number/
class Solution {
 public:
  bool isHappy(int n) {
    std::unordered_set<int> visited;
    while (n != 1 && !visited.count(n)) {
      visited.insert(n);
      int tmp = 0;
      while (n) {
        tmp += (n % 10) * (n % 10);
        n /= 10;
      }
      n = tmp;
    }
    return n == 1;
  }
};
