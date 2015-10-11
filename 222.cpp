// https://leetcode.com/problems/count-complete-tree-nodes/
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
  int get_left_height(TreeNode* root) {
    int height = 0;
    while (root != nullptr) {
      ++height;
      root = root->left;
    }
    return height;
  }
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int lheight = get_left_height(root->left);
    int rheight = get_left_height(root->right);

    if (lheight == rheight) {
      return std::pow(2, lheight) + countNodes(root->right);
    } else {
      return countNodes(root->left) + std::pow(2, rheight);
    }
  }
};
