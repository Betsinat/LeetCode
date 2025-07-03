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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
    
private:
    bool isMirror(TreeNode* leftSub, TreeNode* rightSub) {
        // If both subtrees are null, they're mirrors
        if (leftSub == nullptr && rightSub == nullptr) return true;
        
        // If one is null and the other isn't, they're not mirrors
        if (leftSub == nullptr || rightSub == nullptr) return false;
        
        // Check current node values and recurse
        return (leftSub->val == rightSub->val) && 
               isMirror(leftSub->left, rightSub->right) && 
               isMirror(leftSub->right, rightSub->left);
    }
};