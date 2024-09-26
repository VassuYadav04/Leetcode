class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        auto next = books_.lower_bound(s);
        if (next != books_.end() && next->first < e) {
            return false;
        }
        if (next != books_.begin() && s < (--next)->second) {
            return false;
        }
        books_[s] = e;
        return true;
    }
    
private:
    map<int, int> books_;

};
