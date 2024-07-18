class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        return dfs(distance, root).first;
    }

private:
    pair<int, unordered_map<int, int>> dfs(int distance, TreeNode *node) {
        if (!node) {
            return {0, {}};
        }
        if (!node->left && !node->right) {
            return {0, {{0, 1}}};
        }
        const auto& left = dfs(distance, node->left);
        const auto& right = dfs(distance, node->right);
        int result = left.first + right.first;
        for (const auto& [left_d, left_c] : left.second) {
            for (const auto& [right_d, right_c] : right.second) {
                if (left_d + right_d + 2 <= distance) {
                    result += left_c * right_c;
                }
            }
        }
        unordered_map<int, int> count;
        for (const auto& [left_d, left_c] : left.second) {
            count[left_d + 1] += left_c;
        }
        for (const auto& [right_d, right_c] : right.second) {
            count[right_d + 1] += right_c;
        }
        return {result, count};
    }
};