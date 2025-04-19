class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int currentCount = 1;
        int maxCount = 1;
        while(right < nums.size()){
            if(nums[right] > nums[right - 1]){
                currentCount++;
                maxCount = max(currentCount , maxCount);
                right++;
            }
            else{
                currentCount = 1;
                left = right;
                right++;
            }
        }

          return maxCount;
    }
};