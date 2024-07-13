class LRUCache {
public:
    LRUCache(int capacity) : capa_(capacity) {
    }
    
    int get(int key) {
        if (!map_.count(key)) {
            return -1;
        }
        const auto value = map_[key]->second;
        update(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (capa_ <= 0) {
            return;
        }
    
        if (!map_.count(key) && list_.size() == capa_) {
            auto del = list_.back(); list_.pop_back();
            map_.erase(del.first);
        }
        update(key, value);
    }
    
private:
    list<pair<int, int>> list_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;
    int capa_;
    
    void update(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            list_.erase(it->second);
        }
        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }
};