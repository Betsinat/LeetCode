class Solution {
public:
    // Records each node's parent in a map
    void recordParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            TreeNode* current = nodeQueue.front();
            nodeQueue.pop();
            // Record left child's parent if exists
            if(current->left) {
                parents[current->left] = current;
                nodeQueue.push(current->left);
            }
            // Record right child's parent if exists
            if(current->right) {
                parents[current->right] = current;
                nodeQueue.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Map to store each node's parent
        unordered_map<TreeNode*, TreeNode*> parents;
        recordParents(root, parents);
        // Queue for BFS starting from target node
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(target);
        // Track visited nodes
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int currentDistance = 0;
        // Perform BFS until we reach distance k
        while(!nodeQueue.empty()) {
            // Stop if we've reached the desired distance
            if(currentDistance == k) break;
            int levelSize = nodeQueue.size();
            currentDistance++;
            // Process all nodes at current distance
            for(int i = 0; i < levelSize; i++) {
                TreeNode* current = nodeQueue.front();
                nodeQueue.pop();   
                // Visit left child if exists and not visited
                if(current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    nodeQueue.push(current->left);
                }
                // Visit right child if exists and not visited
                if(current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    nodeQueue.push(current->right);
                }
                // Visit parent if exists and not visited
                TreeNode* parent = parents[current];
                if(parent && !visited[parent]) {
                    visited[parent] = true;
                    nodeQueue.push(parent);
                }
            }
        }
        // Collect all nodes at distance k
        vector<int> result;
        while(!nodeQueue.empty()) {
            result.push_back(nodeQueue.front()->val);
            nodeQueue.pop();
        }
        return result;
    }
};