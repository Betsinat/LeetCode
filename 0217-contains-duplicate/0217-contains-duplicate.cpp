class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        while(left < n-1){
            if (nums[left]==nums[left+1]){
                return true;
            }
            else{
                left++;
            }
        }
                return false;
    }
};