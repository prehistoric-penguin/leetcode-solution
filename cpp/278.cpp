// https://leetcode.com/problems/first-bad-version/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  // inspired by http://en.cppreference.com/w/cpp/algorithm/lower_bound
  int firstBadVersion(int n) {
    int count = n;
    int first = 1;

    while (count > 0) {
      int step = count / 2;
      int val = first + step;
      if (!isBadVersion(val)) {
        first = ++val;
        count -= step + 1;
      } else {
        count = step;
      }
    }
    return first;
  }
};

//----------------------------------------
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};
