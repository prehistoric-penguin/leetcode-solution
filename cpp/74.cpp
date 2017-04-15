// https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return std::accumulate(std::begin(matrix), std::end(matrix), false,
                                [target](bool find, const std::vector<int>& vec) {
                                    return find || std::binary_search(std::begin(vec), std::end(vec), target);
                                });
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        
        int left = 0, right = rows*cols - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[mid / cols][mid % cols];
            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

