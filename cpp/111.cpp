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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        std::queue<std::pair<TreeNode*, int>> queue;
        queue.emplace(root, 1);
        int depth = 0;
        TreeNode* tmp = nullptr;
        while (!queue.empty()) {
            std::tie(tmp, depth) = queue.front();
            queue.pop();
            if (!tmp->left && !tmp->right) {
                break;
            }
            if (tmp->left) queue.emplace(tmp->left, depth + 1);
            if (tmp->right) queue.emplace(tmp->right, depth + 1);
        }
        return depth;
    }
};
