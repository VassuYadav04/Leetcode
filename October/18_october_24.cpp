class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> dp = {{0, 1}};
        int total = 0;
        for (const auto& x : nums) {
            unordered_map<int, int> new_dp = dp;
            for (const auto& [k, v] : dp) {
                new_dp[k | x] += v;
            }
            dp = move(new_dp);
            total |= x;
        }
        return dp[total];
    }
};