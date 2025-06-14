/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
         return dfs(root, 0);
    }
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        currentSum = currentSum * 10 + node->val;
        // If it's a leaf node
        if (!node->left && !node->right) {
            return currentSum;
        }
        // Continue DFS traversal
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};
