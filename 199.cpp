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
        if (!root) return {};
        std::vector<int> result;
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(nullptr);
        
        int preData = 0;
        while (!nodeQueue.empty()) {
            TreeNode* ptr = nodeQueue.front();
            nodeQueue.pop();
            
            // level ends
            if (ptr == nullptr) {
                result.push_back(preData);
                continue;
            }
            preData = ptr->val;
            if (ptr->left != nullptr) {
                nodeQueue.push(ptr->left);
            }
            if (ptr->right != nullptr) {
                nodeQueue.push(ptr->right);
            }
            // current node is right most in level
            if (nodeQueue.size() != 1 && nodeQueue.front() == nullptr) nodeQueue.push(nullptr);
        }
        return result;        
    }
};

