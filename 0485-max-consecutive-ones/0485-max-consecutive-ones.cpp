class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int currentCount = 0;
        while (right < nums.size()) {
            if (nums[right] == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
                right++;
            } else {
                currentCount = 0;
                right++;
                left = right;
            }
        }
        return maxCount;
    }
};