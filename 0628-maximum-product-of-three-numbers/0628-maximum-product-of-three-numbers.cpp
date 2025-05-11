class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        sort(nums.begin(),nums.end());
        int leftProduct = nums[left] * nums[left + 1] * nums[right];
        int rightProduct = nums[right] * nums[right - 1] * nums[right - 2];
                if (leftProduct > rightProduct) {
            return leftProduct;
        } else {
            return rightProduct;
        }
    }

    
};