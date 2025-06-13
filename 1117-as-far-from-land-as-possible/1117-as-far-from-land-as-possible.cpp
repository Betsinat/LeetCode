class Solution {
public:
    int maxDistance(vector<vector<int>>& map) {
        int n = map.size();
        if(!n) return -1;
        queue<pair<int,int>> lands; // stores all land spots
        auto visited = map; // copy to mark visited
        // find all lands first
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j]) {
                    lands.push({i,j});
                }
            }
        }
        // edge cases
        if(lands.empty() || lands.size() == n*n) 
            return -1;
        int dist = -1; // will count steps
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // right,down,left,up
        while(!lands.empty()) {
            int cnt = lands.size();
            dist++;
            while(cnt--) {
                auto [x,y] = lands.front();
                lands.pop();
                for(auto [dx,dy] : dirs) {
                    int nx = x+dx, ny = y+dy;
                    if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny]) {
                        visited[nx][ny] = 1;
                        lands.push({nx,ny});
                    }
                }
            }
        }
        return dist;
    }
};