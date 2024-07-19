class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        for (const auto& row : matrix) {
            rows.emplace(*min_element(row.cbegin(), row.cend()));
        }
        unordered_set<int> cols;
        for (int c = 0; c < matrix[0].size(); ++c) {
            int max_cell = 0;
            for (int r = 0; r < matrix.size(); ++r) {
                max_cell = max(max_cell, matrix[r][c]);
            }
            cols.emplace(max_cell);
        }
        unordered_set<int> intersection = set_intersection(rows, cols);
        return vector<int>(intersection.cbegin(), intersection.cend());
    }

private:
    template<typename T>
    unordered_set<T> set_intersection(const unordered_set<T>& a,
                                      const unordered_set<T>& b) {
        if (a.size() > b.size()) {
            return set_intersection(b, a);
        }
        unordered_set<T> result;
        for (const auto& x : a) {
            if (b.count(x)) {
                result.emplace(x);
            }
        }
        return result;
    }
};