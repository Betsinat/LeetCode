class CityGroups {
    vector<int> parent;
    vector<int> group_size; 
public:
    CityGroups(int n) {
        parent.resize(n);
        group_size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int city) {
        if(parent[city] != city) {
            parent[city] = find(parent[city]);
        }
        return parent[city];
    }
    void merge(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) return;
        if(group_size[rootA] < group_size[rootB]) {
            parent[rootA] = rootB;
            group_size[rootB] += group_size[rootA];
        } else {
            parent[rootB] = rootA;
            group_size[rootA] += group_size[rootB];
        }
    }
    int countGroups() {
        int count = 0;
        for(int i = 0; i < parent.size(); i++) {
            if(parent[i] == i) count++;
        }
        return count;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& connections) {
        int n = connections.size();
        CityGroups groups(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(connections[i][j]) {
                    groups.merge(i, j);
                }
            }
        }
        return groups.countGroups();
    }
};