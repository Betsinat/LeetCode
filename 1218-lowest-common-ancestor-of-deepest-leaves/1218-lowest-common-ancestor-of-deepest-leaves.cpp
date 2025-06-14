class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return findLCA(root).second;
    }
private:
    pair<int, TreeNode*> findLCA(TreeNode* node) {
        if (!node) return {0, nullptr};
        auto left = findLCA(node->left);
        auto right = findLCA(node->right);
        if (left.first == right.first) {
            return {left.first + 1, node};
        } 
        else if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        else {
            return {right.first + 1, right.second};
        }
    }
};