template <typename T>
class DefaultValue {};

template <>
class DefaultValue<int> {
 public:
  operator int() { return -1; }
};

template <typename KeyType, typename ValueType,
          typename DefaultValueType = DefaultValue<ValueType>>
class LRUCacheImpl {
  using ListType = std::list<std::pair<KeyType, ValueType>>;
  using IndexType = std::unordered_map<KeyType, typename ListType::iterator>;

 public:
  LRUCacheImpl(int capacity) : cap_(capacity) {}
  ValueType get(KeyType key) {
    typename IndexType::iterator it = index_.find(key);
    if (it == index_.end()) {
      return DefaultValueType();
    }
    set_latest(it);
    return (it->second)->second;
  }
  void set(KeyType key, ValueType value) {
    typename IndexType::iterator it = index_.find(key);
    // new key
    if (it == index_.end()) {
      if (index_.size() == cap_) {
        index_.erase(list_.front().first);
        list_.pop_front();
      }
      list_.emplace_back(key, value);
      index_.emplace(key, std::prev(std::end(list_)));
    } else {
      // old key, just replace
      (it->second)->second = value;
      set_latest(it);
    }
  }

 private:
  void set_latest(typename IndexType::iterator it) {
    typename ListType::iterator list_it = it->second;
    list_.splice(std::end(list_), list_, list_it, std::next(list_it));
    it->second = std::prev(std::end(list_));
  }
  int cap_;
  ListType list_;
  IndexType index_;
};
using LRUCache = LRUCacheImpl<int, int>;
