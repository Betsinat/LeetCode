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
    bool isCousins(TreeNode* root, int x, int y) {
        // Queue to store nodes along with their parents
        queue<pair<TreeNode*, TreeNode*>> node_queue;
        node_queue.push({root, nullptr});
        TreeNode* x_parent = nullptr;
        TreeNode* y_parent = nullptr;
        bool found_x = false;
        bool found_y = false;
        while (!node_queue.empty()) {
            int nodes_in_current_level = node_queue.size();
            // Process all nodes at the current level
            for (int i = 0; i < nodes_in_current_level; i++) {
                TreeNode* current_node = node_queue.front().first;
                TreeNode* current_parent = node_queue.front().second;
                node_queue.pop();
                // Check if current node is x or y
                if (current_node->val == x) {
                    x_parent = current_parent;
                    found_x = true;
                } else if (current_node->val == y) {
                    y_parent = current_parent;
                    found_y = true;
                }
                // Add children to the queue with current node as parent
                if (current_node->left) {
                    node_queue.push({current_node->left, current_node});
                }
                if (current_node->right) {
                    node_queue.push({current_node->right, current_node});
                }
            }
            // After processing each level, check if we found the nodes
            if (found_x || found_y) {
                // If we found only one of them at this level, they can't be cousins
                if (found_x != found_y) {
                    return false;
                }
                // If we found both, check if they have different parents
                return x_parent != y_parent;
            }
        }
        // If we exit the loop without finding both nodes
        return false;
    }
};