// https://leetcode.com/problems/implement-trie-prefix-tree/
class TrieNode {
 public:
  TrieNode* next[26] = {nullptr};
  bool is_word = false;
};

class Trie {
 public:
  Trie() : root(new TrieNode()) {}
  void insert(const std::string& s) {
    TrieNode* p = root;
    for (char ch : s) {
      if (p->next[ch - 'a'] == nullptr) {
        p->next[ch - 'a'] = new TrieNode();
      }
      p = p->next[ch - 'a'];
    }
    p->is_word = true;
  }
  bool search(const std::string& key) {
    TrieNode* p = find(key);
    return p != nullptr && p->is_word;
  }
  bool startsWith(const std::string& prefix) { return find(prefix) != nullptr; }

 private:
  TrieNode* find(const std::string& key) {
    TrieNode* p = root;
    for (size_t i = 0; i < key.size() && p != nullptr; ++i) {
      p = p->next[key[i] - 'a'];
    }
    return p;
  }
  TrieNode* root;
};
