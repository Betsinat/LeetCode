class Solution {
private:
    // Directions to move: up, right, down, left
    const int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // Helper function to mark all 'O's connected to the given cell
    void markConnected(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();
        // Mark the current cell as visited
        visited[row][col] = true;
        // Explore the four directions
        for (const auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            // Check boundaries and if the cell is an unvisited 'O'
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                board[newRow][newCol] == 'O' && !visited[newRow][newCol]) {
                markConnected(board, visited, newRow, newCol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // Start DFS from 'O's on the borders to mark safe areas
        for (int col = 0; col < cols; ++col) {
            if (board[0][col] == 'O' && !visited[0][col])
                markConnected(board, visited, 0, col);
            if (board[rows - 1][col] == 'O' && !visited[rows - 1][col])
                markConnected(board, visited, rows - 1, col);
        }
        for (int row = 0; row < rows; ++row) {
            if (board[row][0] == 'O' && !visited[row][0])
                markConnected(board, visited, row, 0);
            if (board[row][cols - 1] == 'O' && !visited[row][cols - 1])
                markConnected(board, visited, row, cols - 1);
        }
        // Flip unvisited 'O's to 'X's, because they are surrounded
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'O' && !visited[row][col]) {
                    board[row][col] = 'X';
                }
            }
        }
    }
};
