class MedianFinder {
public:

    void addNum(int num) {
        if (max_heap_.empty() || num > max_heap_.top()) {
            min_heap_.emplace(num);
            if (min_heap_.size() > max_heap_.size() + 1) {
                max_heap_.emplace(min_heap_.top());
                min_heap_.pop();
            }
        } else {
            max_heap_.emplace(num);
            if (max_heap_.size() > min_heap_.size()) {
                min_heap_.emplace(max_heap_.top());
                max_heap_.pop();
            }
        }
    }

    double findMedian() {
        return min_heap_.size() == max_heap_.size() ?
                   (max_heap_.top() + min_heap_.top()) / 2.0 :
                   min_heap_.top();

    }

private:
    priority_queue<int, vector<int>, greater<int>> min_heap_;
    priority_queue<int, vector<int>, less<int>> max_heap_;
};
