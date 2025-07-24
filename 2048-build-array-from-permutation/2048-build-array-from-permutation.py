class Solution(object):
    def buildArray(self, nums):
        ans = []
        for num in range(len(nums)):
            ans.append(nums[nums[num]])
        return ans
        
        