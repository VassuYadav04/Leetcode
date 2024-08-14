class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        q_.emplace(t);
        while (q_.front() < t - 3000) {
            q_.pop();
        }
        return q_.size();
    }

private:
    queue<int> q_;
};
