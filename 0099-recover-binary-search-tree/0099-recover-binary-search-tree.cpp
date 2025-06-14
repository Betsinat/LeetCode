/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr, *temp = nullptr;
        // Morris in-order traversal
        while (root) {
            if (root->left) {
                temp = root->left;
                while (temp->right && temp->right != root) {
                    temp = temp->right;
                }
                if (!temp->right) {
                    temp->right = root;
                    root = root->left;
                } else {
                    // Check for swapped nodes
                    if (prev && prev->val > root->val) {
                        if (!first) first = prev;
                        second = root;
                    }
                    temp->right = nullptr;
                    prev = root;
                    root = root->right;
                }
            } else {
                // Check for swapped nodes
                if (prev && prev->val > root->val) {
                    if (!first) first = prev;
                    second = root;
                }
                prev = root;
                root = root->right;
            }
        }
        // Swap the values
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};