struct TrieNode {
    TrieNode(char ch = ' ') : current(ch) {}
    int val = 0;
    char current;
    bool is_leaf = false;
    std::unique_ptr<TrieNode> children[26];
};
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        auto* p = &root;
        for (auto ch : key) {
            if (!p->children[ch - 'a']) p->children[ch - 'a'] = std::make_unique<TrieNode>(ch);
            p = p->children[ch - 'a'].get();
        }
        p->is_leaf = true;
        p->val = val;
    }
    
    int sum(string prefix) {
        auto* p = &root;
        for (auto ch : prefix) {
            if (!p->children[ch - 'a']) return 0;
            p = p->children[ch - 'a'].get();
        }
        return sum(p);
    }
    int sum(TrieNode* p) {
        if (!p) return 0;
        auto total = 0;
        if (p->is_leaf) total += p->val;
        for (const auto& uptr : p->children) {
            if (uptr) {
                total += sum(uptr.get());
            }
        }
        return total;
    }
    TrieNode root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
