class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum_digits = 0 ;
        int element_sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            element_sum += nums[i];
        }
        for(int i = 0 ; i < nums.size(); i++){
            while(nums[i] > 0){
                sum_digits += nums[i] % 10;
                nums[i] /= 10;
            }
        }
       return abs(element_sum - sum_digits); 
    }
};