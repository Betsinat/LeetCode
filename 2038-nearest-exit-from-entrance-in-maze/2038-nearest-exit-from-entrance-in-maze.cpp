class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // Possible moves: up, down, left, right
        int moves[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int rows = maze.size();
        int cols = maze[0].size();
        queue<pair<int,int>> to_check;
        to_check.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // mark start as visited
        int steps = 0;
        while(!to_check.empty()) {
            int count = to_check.size();
            steps++;
            while(count--) {
                auto [x,y] = to_check.front();
                to_check.pop();
                for(auto& move : moves) {
                    int nx = x + move[0];
                    int ny = y + move[1];
                    // Check if out of bounds
                    if(nx < 0 || nx >= rows || ny < 0 || ny >= cols)
                        continue;
                    // Check if wall or already visited
                    if(maze[nx][ny] != '.')
                        continue;
                    // Check if exit (edge of maze)
                    if(nx == 0 || nx == rows-1 || ny == 0 || ny == cols-1) {
                        // Make sure it's not the entrance
                        if(!(nx == entrance[0] && ny == entrance[1]))
                            return steps;
                    }
                    maze[nx][ny] = '+'; // mark as visited
                    to_check.push({nx,ny});
                }
            }
        }

        return -1;
    }
};