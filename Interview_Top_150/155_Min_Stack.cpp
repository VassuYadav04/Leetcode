class MinStack {
public:
    void push(int number) {
        if (cached_min_with_count_.empty() || cached_min_with_count_.top().first > number) {
            cached_min_with_count_.emplace(number, 1);
        } else if (cached_min_with_count_.top().first == number) {
            ++cached_min_with_count_.top().second;
        }
        elements_.emplace(number);
    }

    void pop() {
        if (cached_min_with_count_.top().first == elements_.top()) {
            if (--cached_min_with_count_.top().second == 0) {
                cached_min_with_count_.pop();
            }
        }
        elements_.pop();
    }

    int top() {
        return elements_.top();
    }

    int getMin() {
        return cached_min_with_count_.top().first;
    }

private:
    stack<int> elements_;
    stack<pair<int, int>> cached_min_with_count_;
};