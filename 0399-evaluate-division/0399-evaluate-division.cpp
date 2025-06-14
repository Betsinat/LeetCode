class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
vector<double>& values,vector<vector<string>>& queries) {
        // Give each variable a number ID
        unordered_map<string, int> var_ids;
        int counter = 0;
        for(auto& eq : equations) {
            string a = eq[0], b = eq[1];
            if(!var_ids.count(a)) var_ids[a] = counter++;
            if(!var_ids.count(b)) var_ids[b] = counter++;
        }
        // Make a grid to store relationships
        vector<vector<double>> connections(counter, vector<double>(counter, -1));
        // Fill direct connections
        for(int i = 0; i < equations.size(); i++) {
            int a_id = var_ids[equations[i][0]];
            int b_id = var_ids[equations[i][1]];
            connections[a_id][b_id] = values[i];
            connections[b_id][a_id] = 1.0 / values[i];
        }
        // Each variable connects to itself
        for(int i = 0; i < counter; i++) {
            connections[i][i] = 1.0;
        }
        // Find all indirect connections
        for(int mid = 0; mid < counter; mid++) {
            for(int from = 0; from < counter; from++) {
                for(int to = 0; to < counter; to++) {
                    if(connections[from][to] == -1 && 
                       connections[from][mid] != -1 && 
                       connections[mid][to] != -1) {
                        connections[from][to] = connections[from][mid] * connections[mid][to];
                    }
                }
            }
        }
        // Answer the queries
        vector<double> answers;
        for(auto& q : queries) {
            if(!var_ids.count(q[0]) || !var_ids.count(q[1])) {
                answers.push_back(-1.0);
                continue;
            }
            answers.push_back(connections[var_ids[q[0]]][var_ids[q[1]]]);
        }
        return answers;
    }
};