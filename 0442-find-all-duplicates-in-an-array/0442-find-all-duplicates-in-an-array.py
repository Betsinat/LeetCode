class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        result = []
        for i in range(len(nums)):
            num = abs(nums[i])
            index = num - 1
            if nums[index] < 0:
                result.append(num)
            else:
                nums[index] = -nums[index]
        return result
                



            

    
        