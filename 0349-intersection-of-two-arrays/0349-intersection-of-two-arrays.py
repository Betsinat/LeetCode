class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        arr = []
        for num1 in nums1:
            for num2 in nums2:
                if num1 == num2:
                    arr.append(num1)
                    break
        s = set(arr)
        return list(s)




        
        
 
        


        