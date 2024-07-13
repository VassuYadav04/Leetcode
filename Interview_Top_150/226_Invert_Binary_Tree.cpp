class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            stack<TreeNode*> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                auto node = nodes.top();
                nodes.pop();
                swap(node->left, node->right);
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
            }
        }
        return root;
    }
};
