class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int left = 0;
        vector<int> New;
        New.push_back(nums[left]); 
        
        for (int right = 1; right < n; right++) {
            if (nums[right] != nums[left]) {
                left = right;
                New.push_back(nums[left]);
            }
        }
        for (int i = 0; i < New.size(); i++) {
            nums[i] = New[i];
        }
        return New.size();
    }
};