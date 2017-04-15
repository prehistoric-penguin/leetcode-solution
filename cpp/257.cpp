// https://leetcode.com/problems/binary-tree-paths/
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
  vector<string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> ans;
    solve(root, {}, ans);

    return ans;
  }
  void solve(TreeNode* root, std::vector<int> vec,
             std::vector<std::string>& ans) {
    if (root == nullptr) {
      return;
    }
    vec.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      add_path(vec, ans);
      return;
    }

    solve(root->left, vec, ans);
    solve(root->right, vec, ans);
  }
  void add_path(std::vector<int>& vec, std::vector<std::string>& ans) {
    ans.push_back(
        std::accumulate(std::begin(vec), std::end(vec), std::string(""),
                        [](const std::string& s, int cur) {
                          if (!s.empty()) {
                            return s + std::string("->") + std::to_string(cur);
                          } else {
                            return std::to_string(cur);
                          }
                        }));
  }
};
