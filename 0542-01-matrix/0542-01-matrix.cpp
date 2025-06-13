class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // If we got an empty grid, just return it back
        if (mat.empty()) return mat;
        int rows = mat.size();
        int cols = mat[0].size();
        // We'll use this line to process cells, starting with all the zeros
        queue<pair<int, int>> processing_line;
        // First, let's scan through the entire grid
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (mat[y][x] == 0) {
                    processing_line.push({y, x});
                } else {
                    mat[y][x] = rows * cols; // A number bigger than any possible distance
                }
            }
        }
        // These are the four directions we can move:
        // up, down, left, right
        int moves[4][2] = {
            {-1, 0}, // Up
            {1, 0},  // Down
            {0, -1}, // Left
            {0, 1}   // Right
        };
        // Now process each cell in our line
        while (!processing_line.empty()) {
            auto current = processing_line.front();
            processing_line.pop();
            int y = current.first;
            int x = current.second;
            for (auto& move : moves) {
                int ny = y + move[0]; // New y position
                int nx = x + move[1]; // New x position
                // First make sure we're still inside the grid
                if (ny >= 0 && ny < rows && nx >= 0 && nx < cols) {
                    if (mat[ny][nx] > mat[y][x] + 1) {
                        mat[ny][nx] = mat[y][x] + 1;
                        // Add this cell to our line to process its neighbors
                        processing_line.push({ny, nx});
                    }
                }
            }
        }
        return mat;
    }
};