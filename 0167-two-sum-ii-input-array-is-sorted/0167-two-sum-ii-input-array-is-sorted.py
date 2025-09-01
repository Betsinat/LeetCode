class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        idx1 = 0
        idx2 = len(numbers) - 1
        sum = 0
        while numbers[idx1] + numbers[idx2] != target:
            sum = numbers[idx1] + numbers[idx2]
            if sum < target:
                idx1 += 1
            else:
                idx2 -= 1
        return [idx1 + 1 , idx2 + 1]
        
        


