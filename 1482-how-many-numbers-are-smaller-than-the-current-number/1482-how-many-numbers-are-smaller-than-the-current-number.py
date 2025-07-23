class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        new_sorted = sorted(nums)
        zipped = zip(new_sorted, range(len(new_sorted)))
        index_map = {}
        for num, i in zipped:
            if num not in index_map:
                index_map[num] = i
        return [index_map[num] for num in nums]

     


      