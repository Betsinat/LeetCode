class Solution(object):
    def sortArrayByParity(self, nums):
        res = []
        for num in nums:
            if num % 2 == 0:
                res.append(num)
        for num in nums:
            if num % 2 != 0:
                res.append(num)
        return res
