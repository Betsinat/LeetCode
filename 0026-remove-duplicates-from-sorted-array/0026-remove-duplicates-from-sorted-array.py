class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        unique_keys = sorted(set(nums))
        for i in range(len(nums)):
           if i < len(unique_keys):
             nums[i] =  unique_keys[i]
           else:
             nums.pop()
        return len(unique_keys)
    
       

        