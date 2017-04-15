// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int kSize = 9;
        int memDigits[9];
        auto hasDuplicateNumber = [&memDigits]() {
            return std::any_of(std::begin(memDigits), std::end(memDigits), [](int val)
                { return val >= 2; }
            );
        };
        auto addChar = [&memDigits](char ch) {
            if (ch != '.') ++memDigits[ch - '1'];
        };
        // rows
        for (int i = 0; i < kSize; ++i) {
            std::fill(std::begin(memDigits), std::end(memDigits), 0);
            for (int j = 0; j < kSize; ++j) {
                addChar(board[i][j]);
                if (hasDuplicateNumber()) return false;
            }
        }
        // columns
        for (int i = 0; i < kSize; ++i) {
            std::fill(std::begin(memDigits), std::end(memDigits), 0);
            for (int j = 0; j < kSize; ++j) {
                addChar(board[j][i]);
                if (hasDuplicateNumber()) return false;
            }            
        }
        // matrix
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::fill(std::begin(memDigits), std::end(memDigits), 0);
                for (int m = 0; m < 3; ++m) {
                    for (int n = 0; n < 3; ++n) {
                        addChar(board[i * 3 + m][j * 3 + n]);
                    }
                }
                if (hasDuplicateNumber()) return false;
            }
        }
        return true;
    }
};

