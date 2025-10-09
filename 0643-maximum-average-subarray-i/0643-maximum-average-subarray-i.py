class Solution(object):
    def findMaxAverage(self, nums, k):
        left = 0 
        total = sum(nums[:k])
        max_avg = float(total)/ k
        for r in range(k , len(nums)):
            total -= nums[left]
            total += nums[r]
            left += 1
            max_avg = (max(max_avg ,  float(total) / k))
        return max_avg

       


        

       
