class Solution(object):
    def applyOperations(self, nums):
        for i in range(len(nums) - 1 ):
            if nums[i] == nums[i+1]:
                nums[i] = nums[i] *2
                nums[i+1] = 0
        new_arr = []
        for i in range(len(nums)):
            if nums[i] != 0:
                new_arr.append(nums[i])
        number_zero = len(nums) - len(new_arr)
        for i in range(number_zero):
            new_arr.append(0)
        return new_arr
            
        

     
         
    
        