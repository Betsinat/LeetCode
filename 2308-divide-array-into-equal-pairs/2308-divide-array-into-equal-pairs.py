class Solution(object):
    def divideArray(self, nums):
        frequency = Counter(nums)
        for count in frequency.values():
            if count % 2 == 1:
                return False
        return True
