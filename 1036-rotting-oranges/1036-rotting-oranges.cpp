class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Copy of the grid to mark visited cells
        vector<vector<int>> visited = grid;
        queue<pair<int, int>> rottenQueue;  // Stores coordinates of rotten oranges
        int freshCount = 0;                 // Counts how many fresh oranges are left
        // Initialize the queue with all initially rotten oranges
        // and count the total number of fresh oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        // If there are no fresh oranges, return 0 minutes
        if (freshCount == 0) return 0;
        // If there are fresh oranges but no rotten ones to start with, impossible to rot them
        if (rottenQueue.empty()) return -1;
        int minutes = -1;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};  // 4 directions: down, up, left, right
        // Start BFS traversal from all initially rotten oranges
        while (!rottenQueue.empty()) {
            int levelSize = rottenQueue.size();
            while (levelSize--) {
                auto [x, y] = rottenQueue.front();
                rottenQueue.pop();
                for (auto [dx, dy] : directions) {
                    int newX = x + dx;
                    int newY = y + dy;
                    // If the adjacent cell has a fresh orange, rot it
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && visited[newX][newY] == 1) {
                        visited[newX][newY] = 2;
                        freshCount--;
                        rottenQueue.push({newX, newY});
                    }
                }
            }
            minutes++;
        }

        // If all fresh oranges are rotten, return minutes; otherwise return -1
        return freshCount == 0 ? minutes : -1;
    }
};
