class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0, double_digits = 0;
        
        for(int num : nums) {
            if (num < 10) single += num;
            else double_digits += num;
        }
        
        return (single > double_digits) || (double_digits > single);
    }
};