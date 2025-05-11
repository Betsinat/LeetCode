class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = n - 1 ;
        while(left < right){
            int mid = floor((left + right)/ 2);
            if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        if (nums[left]== target){
                return left;
            }
            else {
                return -1;
                }


        
    }
};