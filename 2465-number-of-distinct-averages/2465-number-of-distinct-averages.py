class Solution(object):
    def distinctAverages(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        average = set()
        left = 0
        right = len(nums)-1
        nums.sort()
        while left < right:
             current_average = (nums[left] + nums[right])/2.0
             average.add(current_average)
             left +=1
             right -=1
        return len(average)