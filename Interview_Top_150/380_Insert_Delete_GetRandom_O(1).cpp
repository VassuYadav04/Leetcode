class RandomizedSet {
public:
    
    RandomizedSet() : gen_(random_device()()) {
        
    }
    
    
    bool insert(int val) {
        if (used_.count(val)) {
            return false;
        }

        set_.emplace_back(val);
        used_[val] = set_.size() - 1;

        return true;
    }
    
    
    bool remove(int val) {
        if (!used_.count(val)) {
            return false;
        }

        used_[set_.back()] = used_[val];
        swap(set_[used_[val]], set_.back());

        used_.erase(val);
        set_.pop_back();

        return true;
    }
    
   
    int getRandom() {
        uniform_int_distribution<int> dist(0, set_.size() - 1);
        return set_[dist(gen_)];
    }

private:
    vector<int> set_;
    unordered_map<int, int> used_;
    default_random_engine gen_;
};
