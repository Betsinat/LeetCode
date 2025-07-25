class Solution(object):
    def moveZeroes(self, nums):
        idx = 0
        for i in nums:
            if i != 0:            
                nums[idx] = i
                idx += 1
        for j in range(idx, len(nums)):
            nums[j] = 0
        return nums

       
        