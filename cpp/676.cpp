class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {   
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        dict_ = {std::begin(dict), std::end(dict)};
        cache_.clear();
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        auto it = cache_.find(word);
        if (it != std::end(cache_)) return it->second;
        
        auto shadow = word;
        static char char_set[] = "abcdefghijklmnopqrstuvwxyz";
        for (size_t i = 0, sz = word.size(); i < sz; ++i) {
            auto original = word[i];
            for (auto ch : char_set) {
                if (ch == original) continue;
                word[i] = ch;
                if (dict_.find(word) != std::end(dict_)) {
                    cache_[shadow] = true;
                    return true;
                }
            }
            word[i] = original;
        }
        cache_[shadow] = false;
        return false;
    }
    std::unordered_set<std::string> dict_;
    std::unordered_map<std::string, bool> cache_;
};
