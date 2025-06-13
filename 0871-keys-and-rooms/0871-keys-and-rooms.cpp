class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> v;
        queue<int> q;
        v.insert(0);
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int key : rooms[curr]) {
                if (v.find(key) == v.end()) {
                    v.insert(key);
                    q.push(key);
                }
            }
        }

        return v.size() == n;
    }
};
