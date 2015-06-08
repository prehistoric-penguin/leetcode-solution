// https://leetcode.com/problems/lru-cache/

class LRUCache{
public:
    using KeyType = int;
    using ValueType = int;
    using NodeType = std::pair<KeyType, ValueType>;
    using CacheType = std::list<NodeType>;
    
    LRUCache(int capacity):size_(0), capacity_(capacity) {
    }
    
    ValueType get(KeyType key) {
        auto itr = index_.find(key);
        if (itr == index_.cend()) {
            return -1;
        } else {
            setMostRecent(itr->second);
            return itr->second->second;
        }
    }
    
    void set(KeyType key, ValueType value) {
        auto itr = index_.find(key);
        // not existed
        if (itr == index_.end()) {
            // capacity full
            if (size_ == capacity_) {
                int oldestKey = cache_.front().first;
                index_.erase(oldestKey);
                cache_.pop_front();
            } else {
                ++size_;
            }
            cache_.emplace_back(key, value);
            index_.insert(std::make_pair(key, prev(cache_.end())));
        } else {
            // update old value
            itr->second->second = value;
            setMostRecent(itr->second);
        }
    }
private:
    void setMostRecent(CacheType::iterator itr) {
        cache_.splice(std::end(cache_), cache_, itr);
    }
    int size_;
    int capacity_;

    
    CacheType cache_;
    std::unordered_map<KeyType, CacheType::iterator> index_;
};
