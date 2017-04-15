// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(nullptr);
        
        std::vector<int> levelData;
        bool flip = true;
        while (!nodeQueue.empty()) {
            TreeNode* ptr = nodeQueue.front();
            nodeQueue.pop();
            
            // level ends
            if (ptr == nullptr) {
                if (flip = !flip) std::reverse(std::begin(levelData), std::end(levelData));
                result.push_back(std::move(levelData));
                continue;
            }
            levelData.push_back(ptr->val);
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

