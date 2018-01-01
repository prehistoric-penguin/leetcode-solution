class WordDictionary {
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
    WordDictionary() {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto* p = &root;
        for (auto ch : word) {
            if (!p->children[ch - 'a']) p->children[ch - 'a'] = std::make_unique<TrieNode>(ch);
            p = p->children[ch - 'a'].get();
        }
        p->is_leaf = true;        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(std::begin(word), std::end(word), &root);
    }
    template <typename T>
    bool search(T first, T last, TrieNode* node) {
        if (node == nullptr) return false;
        if (first == last) return node->is_leaf;

        if (*first == '.') {
            bool ok = false;
            for (const auto& uptr : node->children) {
                if (uptr) {
                    ok |= search(std::next(first), last, uptr.get());
                }
            }
            return ok;
        }
        return search(std::next(first), last, node->children[*first - 'a'].get());
    }
    private:
    TrieNode root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
