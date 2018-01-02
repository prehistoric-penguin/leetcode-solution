struct TrieNode {
    TrieNode(char ch = ' ') : current(ch) {}
    char current;
    bool is_leaf = false;
    std::unique_ptr<TrieNode> children[26];
};
struct Trie {
    void insert(const std::vector<std::string>& vec) {
        for (const auto& s : vec) {
            insert(s);
        }
    }
    void insert(string key) {
        auto* p = &root;
        for (auto ch : key) {
            if (!p->children[ch - 'a']) p->children[ch - 'a'] = std::make_unique<TrieNode>(ch);
            p = p->children[ch - 'a'].get();
        }
        p->is_leaf = true;
    }
    std::string prefix(const std::string& str) {
        auto *p = &root;
        for (size_t i = 0, sz = str.size(); i < sz; ++i) {
            p = p->children[str[i] - 'a'].get();
            if (!p) return "";
            if (p->is_leaf) return str.substr(0, i + 1);
        }
        return p->is_leaf ? str : "";
    }
    TrieNode root;
};
class Solution {
public:
    string replaceWords(vector<string>& dict, const string& sentence) {
        Trie trie;
        trie.insert(dict);
        std::vector<std::string> words;
        std::istringstream iss(sentence);
        std::copy(std::istream_iterator<std::string>(iss),
                 std::istream_iterator<std::string>(),
                 std::back_inserter(words));
        std::transform(
            std::begin(words), std::end(words),
            std::begin(words),[&](const std::string& w){
                const auto& pre = trie.prefix(w);
                return pre.empty() ? w : pre;
        });
        return std::accumulate(std::begin(words), std::end(words), std::string(""),
                              [](const std::string& pre, const std::string& cur) {
                                  return pre.empty() ? cur : pre + " " + cur;
                              });
    }
};
