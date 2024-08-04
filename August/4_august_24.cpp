class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        static const int MOD = 1e9 + 7;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (int i = 0; i < n; ++i) {
            min_heap.emplace(nums[i], i + 1);
        }
        int result = 0;
        for (int i = 1; i <= right; ++i) {
            auto [total, j] = min_heap.top(); min_heap.pop();
            if (i >= left) {
                result = (result + total) % MOD;
            }
            if (j + 1 <= n) {
                min_heap.emplace(total + nums[j], j + 1);
            }
        }
        return result;
    }
};