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
        while (!queue.empty()) {
            auto&& p = queue.front();
            auto* n = p.first;
            depth = p.second;
            queue.pop();
            if (!n->left && !n->right) {
                break;
            }
            if (n->left) queue.emplace(n->left, depth + 1);
            if (n->right) queue.emplace(n->right, depth + 1);
        }
        return depth;
    }
};
