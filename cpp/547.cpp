
class Solution {
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        auto n = matrix.size();
        std::vector<size_t> leads(n);
        std::iota(std::begin(leads), std::end(leads), 0);
        size_t group_nums = n;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                if (matrix[i][j]) {
                    auto n1 = find(i, leads);
                    auto n2 = find(j, leads);
                    if (n1 != n2) {
                        leads[n1] = n2;
                        --group_nums;
                    }
                }
            }
        }
        return group_nums;
    }
    int find(size_t i, std::vector<size_t>& parents) {
        return parents[i] == i ? i : find(parents[i], parents);
    }
};
