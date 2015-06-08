// https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traversal(root, result);
        return result;
    }
    void traversal(TreeNode* root, std::vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        traversal(root->left, result);
        traversal(root->right, result);
    }
};

