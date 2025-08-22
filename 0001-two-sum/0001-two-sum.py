from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        twoSum_map = defaultdict(list)
        result = []
        for i in range(len(nums)):
                twoSum_map[nums[i]].append(i)
        for num in nums:
            complement = target - num
            if complement not in twoSum_map:
                continue
            if num == complement:
                if len(twoSum_map[num]) >= 2:
                    idx1, idx2 = twoSum_map[num][0], twoSum_map[num][1]
                    return [idx1, idx2]
            else:
                idx1, idx2 = twoSum_map[num][0], twoSum_map[complement][0]
                return [idx1, idx2]

           
       



        