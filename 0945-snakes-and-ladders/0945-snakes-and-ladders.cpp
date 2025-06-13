class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int board_size = board.size();
        int current_label = 1;
        // Create a mapping from cell numbers to board positions
        vector<pair<int, int>> cell_positions(board_size * board_size + 1);
        // Generate column numbers (0 to board_size-1)
        vector<int> columns(board_size);
        for(int i = 0; i < board_size; i++) {
            columns[i] = i;
        }
        // Fill the cell_positions map with row/column coordinates
        // We start from the bottom row and work our way up
        for(int row = board_size - 1; row >= 0; row--) {
            for(int column : columns) {
                cell_positions[current_label] = {row, column};
                current_label++;
            }
            reverse(columns.begin(), columns.end());
        }
        
        // Track minimum moves to reach each cell
        vector<int> moves(board_size * board_size + 1, -1);
        moves[1] = 0; // Starting position takes 0 moves
        queue<int> cells_to_explore;
        cells_to_explore.push(1); // Start from cell 1
        while(!cells_to_explore.empty()) {
            int current_cell = cells_to_explore.front();
            cells_to_explore.pop();
            // Explore all possible next moves (dice rolls 1-6)
            for(int next_cell = current_cell + 1; next_cell <= min(current_cell + 6, board_size * board_size); next_cell++) {
                auto [row, col] = cell_positions[next_cell];
                int destination = board[row][col] != -1 ? board[row][col] : next_cell;
                // If we haven't reached this destination yet
                if(moves[destination] == -1) {
                    moves[destination] = moves[current_cell] + 1;
                    cells_to_explore.push(destination);
                    // Early exit if we reach the end
                    if(destination == board_size * board_size) {
                        return moves[destination];
                    }
                }
            }
        }
        
        return moves[board_size * board_size];
    }
};