// https://leetcode.com/problems/search-a-2d-matrix-ii/
//
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    int row = matrix.size();
    int col = matrix[0].size();

    int x = 0, y = col - 1;
    while (x < row && y >= 0) {
      if (matrix[x][y] == target) {
        return true;
      } else if (matrix[x][y] > target) {
        --y;
      } else {
        ++x;
      }
    }
    return false;
  }
};
