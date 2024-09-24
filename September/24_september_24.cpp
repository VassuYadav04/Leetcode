class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> lookup = {0};
        for (auto x : arr1) {
            for (; x; x /= 10) {
                lookup.emplace(x);
            }
        }
        int result = 0;
        for (auto x : arr2) {
            int l = size(to_string(x));
            for (; !lookup.count(x); x /= 10) {
                --l;
            }
            result = max(result, l);
        }
        return result;
    }
};