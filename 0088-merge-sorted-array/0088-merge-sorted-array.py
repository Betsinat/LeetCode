class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        first , second = 0 , 0
        merged = []
        while first < m and second < n:
            if nums1[first] < nums2[second]:
                merged.append(nums1[first])
                first += 1
            else:
                merged.append(nums2[second])
                second += 1
        merged.extend(nums1[first:m])
        merged.extend(nums2[second:n])
        for i in range(len(merged)):
            nums1[i] = merged[i]
       

        