class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        std::vector<std::pair<int, int>> bounds;
        auto add_o = [&board, &bounds](int i, int j) {
            if (board[i][j] == 'O') bounds.emplace_back(i, j);
        };
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; ++i) { add_o(i, 0); add_o(i, cols - 1); }
        for (int j = 0; j < cols; ++j) { add_o(0, j); add_o(rows - 1, j); }
        for (const auto& p : bounds) {
            if (board[p.first][p.second] == 'O') {
                bfs(p.first, p.second, rows, cols, board);
            }
        }
        for (int i = 0;i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                board[i][j] = board[i][j] == 'B' ? 'O' : 'X';
            }
        }
    }
    void bfs(int i, int j, int rows, int cols, vector<vector<char>>& board) {
        std::queue<std::pair<int, int>> queue;
        queue.emplace(i, j);
        std::pair<int, int> adjs[] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        auto valid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < rows && j < cols;
        };
        auto add_adjacent = [&](int i, int j) {
            if (board[i][j] != 'O')
                return;
            board[i][j] = 'B';
            for (const auto& p : adjs) {
                auto x = i + p.first;
                auto y = j + p.second;
                if (valid(x, y) && board[x][y] == 'O') {
                    queue.emplace(x, y);
                }
            }
        };
        while (!queue.empty()) {
            auto&& p = queue.front();
            queue.pop();
            
            add_adjacent(p.first, p.second);
        }
    }
};
