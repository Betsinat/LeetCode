class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Special case: single cell grid
        if (rows == 1 && cols == 1) return true;
        // Create a mapping from grid positions to node IDs
        vector<vector<int>> node_ids(rows, vector<int>(cols));
        int current_id = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                node_ids[i][j] = current_id++;
            }
        }
        // Build the adjacency list
        vector<vector<int>> connections(current_id);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int street_type = grid[i][j];
                int current_node = node_ids[i][j];
                // Connect based on street type
                switch (street_type) {
                    case 1: // Left-right street
                        if (j > 0) 
                            connections[current_node].push_back(node_ids[i][j-1]);
                        if (j < cols-1) 
                            connections[current_node].push_back(node_ids[i][j+1]);
                        break;
                    case 2: // Up-down street
                        if (i > 0) 
                            connections[current_node].push_back(node_ids[i-1][j]);
                        if (i < rows-1) 
                            connections[current_node].push_back(node_ids[i+1][j]);
                        break;
                    case 3: // Left-down street
                        if (j > 0) 
                            connections[current_node].push_back(node_ids[i][j-1]);
                        if (i < rows-1) 
                            connections[current_node].push_back(node_ids[i+1][j]);
                        break;
                    case 4: // Right-down street
                        if (j < cols-1) 
                            connections[current_node].push_back(node_ids[i][j+1]);
                        if (i < rows-1) 
                            connections[current_node].push_back(node_ids[i+1][j]);
                        break;
                    case 5: // Left-up street
                        if (j > 0) 
                            connections[current_node].push_back(node_ids[i][j-1]);
                        if (i > 0) 
                            connections[current_node].push_back(node_ids[i-1][j]);
                        break;
                    case 6: // Right-up street
                        if (j < cols-1) 
                            connections[current_node].push_back(node_ids[i][j+1]);
                        if (i > 0) 
                            connections[current_node].push_back(node_ids[i-1][j]);
                        break;
                }
            }
        }
        // Check path using BFS
        vector<bool> visited(current_id, false);
        queue<int> to_visit;
        to_visit.push(0);
        visited[0] = true;
        while (!to_visit.empty()) {
            int current = to_visit.front();
            to_visit.pop();
            // Check if we reached the destination
            if (current == current_id - 1) {
                return true;
            }
            // Visit all connected neighbors
            for (int neighbor : connections[current]) {
                // Verify the connection is bidirectional
                bool is_valid_connection = false;
                for (int reverse_neighbor : connections[neighbor]) {
                    if (reverse_neighbor == current) {
                        is_valid_connection = true;
                        break;
                    }
                }
                if (!visited[neighbor] && is_valid_connection) {
                    visited[neighbor] = true;
                    to_visit.push(neighbor);
                }
            }
        }
        
        return false;
    }
};