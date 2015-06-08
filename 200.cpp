// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return num_;
        setRows(grid.size());
        setCols(grid.front().size());
        initVis();
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (validPos(grid, i, j)) {
                    ++num_;
                    traverse(grid, i, j);
                }
            }
        }
        
        return num_;
    }
    void traverse(vector<vector<char>>& grid, int x, int y) {
        if (!validPos(grid, x, y)) return;
        setVisited(x, y);
        traverse(grid, x + 1, y);
        traverse(grid, x, y + 1);
        traverse(grid, x - 1, y);
        traverse(grid, x, y - 1);
    }
    bool validPos(vector<vector<char>>& grid, int x, int y) {
        return x >= 0 && x < rows_ &&
                y >= 0 && y < cols_ &&
                grid[x][y] == '1' &&
                visited_[x][y] == false;
    }
    void setVisited(int x, int y) { visited_[x][y] = true; }
    void setRows(int r) { rows_ = r; }
    void setCols(int c) { cols_ = c; }
    void initVis() { visited_ = std::vector<std::vector<bool>>(rows_, std::vector<bool>(cols_, false)); }
    int num_{0};
    int rows_{0};
    int cols_{0};
    std::vector<std::vector<bool>> visited_;
};
