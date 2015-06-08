// https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) return true;
        if (leftNode == nullptr || rightNode == nullptr) return false;
        return leftNode->val == rightNode->val &&
                isSymmetric(leftNode->left, rightNode->right) &&
                isSymmetric(leftNode->right, rightNode->left);
    }
};

