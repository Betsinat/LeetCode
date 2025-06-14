#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double howFar(int x1, int y1, int x2, int y2) {
        // Just basic pythagorean theorem
        long long xGap = x1 - x2;
        long long yGap = y1 - y2;
        return sqrt(xGap*xGap + yGap*yGap);
    }
    void chainReaction(int bomb, vector<int>& wentBoom, int& boomTotal, vector<vector<int>>& triggers) {
        wentBoom[bomb] = 1; // Mark this one as exploded
        boomTotal++; // Count it
        // Set off all the bombs this one triggers
        for(int next : triggers[bomb]) {
            if(!wentBoom[next]) {
                chainReaction(next, wentBoom, boomTotal, triggers);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> triggers(n); // Which bombs each bomb can set off
        // Check all bomb pairs to see who triggers who
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                double gap = howFar(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]);
                // Can bomb i set off bomb j?
                if(gap <= bombs[i][2]) {
                    triggers[i].push_back(j);
                }
                // Can bomb j set off bomb i?
                if(gap <= bombs[j][2]) {
                    triggers[j].push_back(i);
                }
            }
        }
        int maxBoom = 0;
        // Try starting with each bomb
        for(int start = 0; start < n; start++) {
            vector<int> wentBoom(n, 0); // Track explosions
            int currentBoom = 0;
            chainReaction(start, wentBoom, currentBoom, triggers);
            // Keep the biggest chain we find
            if(currentBoom > maxBoom) {
                maxBoom = currentBoom;
            }
        }
        return maxBoom;
    }
};