class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string src, dst;
        dfs(root, startValue, &src);
        dfs(root, destValue, &dst);
        while (!empty(src) && !empty(dst) && src.back() == dst.back()) {
            src.pop_back();
            dst.pop_back();
        }
        reverse(begin(dst), end(dst));
        return string(size(src), 'U') + dst;
    }

private:
    bool dfs(TreeNode *curr, int val, string *path) {
        if (curr->val == val) {
            return true;
        }
        if (curr->left && dfs(curr->left, val, path)) {
            path->push_back('L');
        } else if (curr->right && dfs(curr->right, val, path)) {
            path->push_back('R');
        }
        return !empty(*path);
    }
};