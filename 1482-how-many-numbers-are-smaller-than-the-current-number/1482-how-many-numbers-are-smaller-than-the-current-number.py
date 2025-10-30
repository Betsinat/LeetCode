class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
     count = 0
     n = []
     j = 1
     for i in range(len(nums)):
        count = 0
        for j in range(len(nums)):
            if nums[j] < nums[i]:
                count +=1
        n.append(count)
     return n
     