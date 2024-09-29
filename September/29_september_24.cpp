class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if (!bucketOfKey_.count(key)) {
            bucketOfKey_[key] = buckets_.insert(buckets_.begin(), {0, {key}});
        }
            
        auto next = bucketOfKey_[key], bucket = next++;
        if (next == buckets_.end() || next->value > bucket->value + 1) {
            next = buckets_.insert(next, {bucket->value + 1, {}});
        }
        next->keys.insert(key);
        bucketOfKey_[key] = next;
        
        bucket->keys.erase(key);
        if (bucket->keys.empty()) {
            buckets_.erase(bucket);
        }
    }
    
    void dec(string key) {
        if (!bucketOfKey_.count(key)) {
            return;
        }

        auto prev = bucketOfKey_[key], bucket = prev--;
        bucketOfKey_.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets_.begin() || prev->value < bucket->value - 1) {
                prev = buckets_.insert(bucket, {bucket->value - 1, {}});
            }
            prev->keys.insert(key);
            bucketOfKey_[key] = prev;
        }
        
        bucket->keys.erase(key);
        if (bucket->keys.empty()) {
            buckets_.erase(bucket);
        }
    }
    
    string getMaxKey() {
        return buckets_.empty() ? "" : *(buckets_.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        return buckets_.empty() ? "" : *(buckets_.begin()->keys.begin());
    }

private:
    struct Bucket {
        int value;
        unordered_set<string> keys;
    };
    list<Bucket> buckets_;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey_;
};
