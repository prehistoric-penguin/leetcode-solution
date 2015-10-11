// https://leetcode.com/problems/count-primes/
class Solution {
 public:
  int countPrimes(int n) {
    if (n < 2) {
      return 0;
    }
    std::vector<int> prime_table(n, 1);

    int val = sqrt(n) + 1;
    for (int i = 2; i < val; ++i) {
      if (!prime_table[i]) {
        continue;
      }
      for (int j = i * i; j < n; j += i) {
        prime_table[j] = 0;
      }
    }

    return std::count(std::next(std::begin(prime_table), 2),
                      std::end(prime_table), 1);
  }
};
