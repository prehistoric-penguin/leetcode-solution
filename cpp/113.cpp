/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        std::vector<std::vector<int>> ans;
        dfs(root, sum, {}, ans);
        return ans;
    }
    void dfs(TreeNode* root, int cur, std::vector<int> path, std::vector<std::vector<int>>& ans) {
        if (!root) return;
        cur -= root->val;
        path.emplace_back(root->val);
        if (!root->left && !root->right) {
            if (cur == 0) {
                ans.emplace_back(std::move(path));
            }
            return;
        }
        dfs(root->left, cur, path, ans);
        dfs(root->right, cur, path, ans);
    }
};
