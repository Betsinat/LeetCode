class Solution(object):
    def applyOperations(self, nums):
      for i in range(len(nums) - 1):
         if nums[i] == nums[i+1]:
            nums[i] = nums[i] * 2
            nums[i+1] = 0
      num = [x for x in nums if x != 0]
      zeros = [0] * (len(nums) - len(num))
      num.extend(zeros)
      return(num)
  
        
         
    
        