
class Solution(object):
    def frequencySort(self, nums):
     count = Counter(nums)
     nums.sort(key = lambda x : (count[x] , - x))
     return nums
       

       