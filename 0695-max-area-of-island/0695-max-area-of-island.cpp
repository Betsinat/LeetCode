class Solution {
private:
    // Directions: left, up, right, down
    const int directions[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    // BFS approach to explore an island
    int exploreIslandBFS(int startRow, int startCol, int rows, int cols, 
    vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        queue<pair<int, int>> islandCells;
        islandCells.push({startRow, startCol});
        visited[startRow][startCol] = true;
        int area = 1;
        while (!islandCells.empty()) {
            auto current = islandCells.front();
            islandCells.pop();
            // Check all four neighboring cells
            for (auto dir : directions) {
                int newRow = current.first + dir[0];
                int newCol = current.second + dir[1];
                // Check if the neighbor is valid and part of the island
                if (newRow >= 0 && newRow < rows && 
                    newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == 1 && 
                    !visited[newRow][newCol]) {
                    islandCells.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                    area++;
                }
            }
        }
        return area;
    }
    // DFS approach to explore an island
    int exploreIslandDFS(int row, int col, int rows, int cols,
     vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if (row < 0 || row >= rows || col < 0 || col >= cols ||
            grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }
        visited[row][col] = true;
        int area = 1;
        // Explore all four directions
        for (auto dir : directions) {
            area += exploreIslandDFS(row + dir[0], col + dir[1], rows, cols, visited, grid);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int maxArea = 0;
        // Check every cell in the grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    // Choose either BFS or DFS approach here:
                    int currentArea = exploreIslandDFS(r, c, rows, cols, visited, grid);
                    // int currentArea = exploreIslandBFS(r, c, rows, cols, visited, grid);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }
};