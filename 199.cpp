// https://leetcode.com/problems/binary-tree-right-side-view/
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
  vector<int> rightSideView(TreeNode* root) {
    std::vector<int> vec;
    solve(root, 0, vec);

    return vec;
  }
  void solve(TreeNode* root, int height, std::vector<int>& vec) {
    if (root == nullptr) {
      return;
    }
    if (height >= vec.size()) {
      vec.push_back(root->val);
    }
    solve(root->right, height + 1, vec);
    solve(root->left, height + 1, vec);
  }
};
