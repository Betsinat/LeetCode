class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        int left = 0;
        while (left < n - 1) { 
            if (nums[left] == nums[left + 1]) {
                left += 2;
            } else {
                return nums[left]; 
            }
        }
        return nums[n - 1]; 
    }
};

