
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& busRoutes, int start, int end) {
        // If we're already at the destination
        if(start == end) return 0;
        // Create a map from bus stops to route indices
        unordered_map<int, vector<int>> stopToBusRoutes;
        // Fill the map - which buses go through which stops
        for(int routeNum = 0; routeNum < busRoutes.size(); routeNum++) {
            for(int busStop : busRoutes[routeNum]) {
                stopToBusRoutes[busStop].push_back(routeNum);
            }
        }
        // Track which bus routes we've already taken
        vector<bool> takenRoute(busRoutes.size(), false);
        // Queue for BFS - stores bus stops to explore
        queue<int> stopsToExplore;
        stopsToExplore.push(start);
        int busCount = 0;
        while(!stopsToExplore.empty()) {
            int stopsInCurrentLevel = stopsToExplore.size();
            busCount++;
            while(stopsInCurrentLevel--) {
                int currentStop = stopsToExplore.front();
                stopsToExplore.pop();
                // Check all bus routes that pass through this stop
                for(int routeNum : stopToBusRoutes[currentStop]) {
                    // Skip routes we've already taken
                    if(takenRoute[routeNum]) continue;
                    takenRoute[routeNum] = true;
                    // Check all stops on this bus route
                    for(int nextStop : busRoutes[routeNum]) {
                        if(nextStop == end) {
                            return busCount;
                        }
                        stopsToExplore.push(nextStop);
                    }
                }
            }
        }
        // If we never reached the destination
        return -1;
    }
};