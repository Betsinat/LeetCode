class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        running = [nums[0]]
        for i in range(1 , len(nums)):
            running.append(running[-1] + nums[i])
        return running
       


      
        

        