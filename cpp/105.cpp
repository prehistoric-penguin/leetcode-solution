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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto build = [](auto&& self, auto first1, auto last1, auto first2, auto last2) -> TreeNode*{
            if (first1 == last1 || first2 == last2) return nullptr;

            auto* root = new TreeNode(*first1);
            auto it = std::find(first2, last2, *first1);
            auto mid = std::next(std::next(first1, std::distance(first2, it)));
            root->left = self(self, std::next(first1), mid, first2, it);
            root->right = self(self, mid, last1, std::next(it), last2);

            return root;
        };
        return build(build, std::begin(preorder), std::end(preorder),
                    std::begin(inorder), std::end(inorder));
    }
    /*
    template <typename T>
    TreeNode* build(T first1, T last1, T first2, T last2) {
        if (first1 == last1 || first2 == last2) return nullptr;
        
        auto* root = new TreeNode(*first1);
        auto it = std::find(first2, last2, *first1);
        auto mid = std::next(std::next(first1, std::distance(first2, it)));
        root->left = build(std::next(first1), mid, first2, it);
        root->right = build(mid, last1, std::next(it), last2);
        
        return root;
    }*/
};
