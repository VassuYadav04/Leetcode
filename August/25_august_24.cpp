class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode *, bool>> s;
        s.emplace(root, false);
        while (!s.empty()) {
            bool visited;
            tie(root, visited) = s.top();
            s.pop();
            if (root == nullptr) {
                continue;
            }
            if (visited) {
                res.emplace_back(root->val);
            } else {
                s.emplace(root, true);
                s.emplace(root->right, false);
                s.emplace(root->left, false);
            }
        }
        return res;
    }
};