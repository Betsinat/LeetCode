#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& m) {
        if(m.size()==0) return m;
        queue<pair<int,int>> q; 
        int rows=m.size(), cols=m[0].size();
        // first pass to find waters
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(m[i][j]==1) {
                    m[i][j]=0; 
                    q.push({i,j});
                }
                else m[i][j]=-1;
            }
        }
        // up down left right
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()) {
            auto p=q.front(); q.pop();
            for(auto d:dirs) {
                int ni=p.first+d[0];
                int nj=p.second+d[1];
                if(ni>=0 && ni<rows && nj>=0 && nj<cols) {
                    if(m[ni][nj]==-1) {
                        m[ni][nj]=m[p.first][p.second]+1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return m;
    }
};