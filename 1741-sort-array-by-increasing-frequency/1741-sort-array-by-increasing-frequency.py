
class Solution(object):
    def frequencySort(self, nums):
        frequency = Counter(nums)
        new_sorted = sorted(nums, key = lambda x : (frequency[x] , -x))
        return new_sorted

       