class Solution {
public:
    struct TrieNode {
        TrieNode(char c = ' '):cur_char(c) {}

        char cur_char;
        bool is_leaf = false;
        unique_ptr<TrieNode> children[26] = {nullptr};
    };
    struct Trie {
        Trie() = default;
        void add(const std::string& str) {
            auto* p = &root;
            for (auto ch : str) {
                if (!p->children[ch - 'a']) {
                    p->children[ch - 'a'] = std::make_unique<TrieNode>(ch);
                }
                p = p->children[ch - 'a'].get();
            }
            p->is_leaf = true;
        }
        bool find(const std::string& str) {
            auto* p = &root;
            for (auto ch : str) {
                if (!p->children[ch - 'a'] || !p->children[ch - 'a']->is_leaf) return false;
                p = p->children[ch  - 'a'].get();
            }
            return p->is_leaf;
        }
        TrieNode root;
    };
    string longestWord(vector<string>& words) {
        if (words.empty()) return {};
        Trie trie;
        for (const auto& w : words) {
            trie.add(w);
        }
        std::string ans;
        for (const auto& w : words) {
            if (!trie.find(w)) continue;
            if (w.size() > ans.size() || (w.size() == ans.size() && w < ans)) ans = w;
        }
        return ans;
    }
};
