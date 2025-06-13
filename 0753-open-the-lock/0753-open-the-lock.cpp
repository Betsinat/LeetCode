class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // First, check if we're already at the right combination
        if (target == "0000") {
            return 0;  
        }
        // Make a quick lookup for deadends
        unordered_set<string> no_go(deadends.begin(), deadends.end());
        if (no_go.count("0000")) {
            return -1;  
        }
        // We'll use this queue to try combinations one by one
        // It stores both the combo and how many moves we've tried
        queue<pair<string, int>> to_try;
        to_try.push({"0000", 0});
        // Remember combos we've already checked
        unordered_set<string> tried_before;
        tried_before.insert("0000");
        while (!to_try.empty()) {
            auto current = to_try.front();
            to_try.pop();
            string current_combo = current.first;
            int current_moves = current.second;
            if (current_combo == target) {
                return current_moves;
            }
            // Try turning each wheel both ways
            for (int wheel = 0; wheel < 4; wheel++) {
                // Make copies to mess with
                string turn_up = current_combo;
                string turn_down = current_combo;
                // Turn the wheel up (0→1→...→9→0)
                if (turn_up[wheel] == '9') {
                    turn_up[wheel] = '0';
                } else {
                    turn_up[wheel]++;
                }
                // Turn the wheel down (0→9→8→...→0)
                if (turn_down[wheel] == '0') {
                    turn_down[wheel] = '9';
                } else {
                    turn_down[wheel]--;
                }
                // If this new combo isn't blocked and we haven't tried it yet...
                if (!no_go.count(turn_up) && !tried_before.count(turn_up)) {
                    tried_before.insert(turn_up);
                    to_try.push({turn_up, current_moves + 1});
                }
                if (!no_go.count(turn_down) && !tried_before.count(turn_down)) {
                    tried_before.insert(turn_down);
                    to_try.push({turn_down, current_moves + 1});
                }
            }
        }
        return -1;
    }
};