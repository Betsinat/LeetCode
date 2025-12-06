class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr = []
        n = len(nums)
        for i in range(n+1):
            arr.append(i)
        return sum(arr) - sum(nums)
       


        