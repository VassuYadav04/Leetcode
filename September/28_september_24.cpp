class MyCircularDeque {
public:
    MyCircularDeque(int k) :
        start_(0),
        size_(0),
        buffer_(k, 0) {
        
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        start_ = (start_ - 1 + buffer_.size()) % buffer_.size();
        buffer_[start_] = value;
        ++size_;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        buffer_[(start_ + size_) % buffer_.size()] = value;
        ++size_;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        start_ = (start_ + 1) % buffer_.size();
        --size_;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size_;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : buffer_[start_];
    }
    
    int getRear() {
        return isEmpty() ? -1 : buffer_[(start_ + size_ - 1) % buffer_.size()];
    }
    
    bool isEmpty() {
        return size_ == 0;
    }
    
    bool isFull() {
        return size_ == buffer_.size();
    }

private:
    int start_;
    int size_;
    vector<int> buffer_;
};