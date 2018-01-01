class Trie {
public:
    struct TrieNode {
        TrieNode() = default;
        TrieNode(char ch) : current(ch) {}
        char current = ' ';
        bool is_leaf = false;
        static constexpr size_t kChildrenNum = 26;
        std::unique_ptr<TrieNode> children[kChildrenNum];
    };
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto* p = &root;
        for (auto ch : word) {
            if (!p->children[ch - 'a']) p->children[ch - 'a'] = std::make_unique<TrieNode>(ch);
            p = p->children[ch - 'a'].get();
        }
        p->is_leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto* p = find_to_end(word);
        return p && p->is_leaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find_to_end(prefix) != nullptr;
    }
    private:
    TrieNode* find_to_end(const std::string& str) {
        auto *p = &root;
        for (auto ch : str) {
            if (!p->children[ch - 'a']) return nullptr;
            p = p->children[ch - 'a'].get();
        }
        return p;
    }
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
