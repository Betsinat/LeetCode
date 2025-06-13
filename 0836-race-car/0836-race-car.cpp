class Solution {
public:
    int racecar(int target) {
        // steps[i] = minimum moves to reach position i
        vector<int> steps(target+1, INT_MAX);
        int power = 1; // tracks acceleration sequence
        for(int pos = 1; pos <= target; pos++) {
            // Case 1: Perfect power-of-2 position (like 1, 3, 7)
            if(pos == (1 << power) - 1) {
                steps[pos] = power;
                power++;
                continue;
            } 
            // Case 2: Overshoot and reverse
            int overshoot = (1 << power) - 1;
            steps[pos] = min(steps[pos], power + 1 + steps[overshoot - pos]);
            // Case 3: Undershoot and adjust
            int undershoot = (1 << (power-1)) - 1;
            for(int back = 0; back < power-1; back++) {
                int back_pos = (1 << back) - 1;
                steps[pos] = min(steps[pos],
                              (power-1) + 2 + back + 
                              steps[pos - undershoot + back_pos]);
            }
        }
        
        return steps[target];
    }
};