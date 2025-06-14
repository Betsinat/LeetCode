class Solution {
public:
    int total = 0;
    void explore(TreeNode* node) {
        if(!node) return;
        // If current node is even, check its grandchildren
        if(node->val % 2 == 0) {
            checkGrandchildren(node, 0);
        }
        // Continue exploring the tree
        explore(node->left);
        explore(node->right);
    }
    void checkGrandchildren(TreeNode* node, int depth) {
        if(!node) return;
        // When we reach grandchild level (depth 2)
        if(depth == 2) {
            total += node->val;
            return;
        }
        // Go deeper into left and right children
        checkGrandchildren(node->left, depth + 1);
        checkGrandchildren(node->right, depth + 1);
    }
    int sumEvenGrandparent(TreeNode* root) {
        explore(root);
        return total;
    }
};