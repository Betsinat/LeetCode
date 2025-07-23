class Solution(object):
    def divideArray(self, nums):
        frequency = Counter(nums)
        if len(nums) % 2 == 1:
            return False
        for count in frequency.values():
            if count % 2 == 1:
                return False
        return True
