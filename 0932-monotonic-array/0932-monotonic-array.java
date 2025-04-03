class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean increasing = true;
        boolean decreasing = true;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false;  // If it's increasing, it can't be decreasing
            }
            if (nums[i] < nums[i - 1]) {
                increasing = false;  // If it's decreasing, it can't be increasing
            }
        }
        return increasing || decreasing;
    }
}
