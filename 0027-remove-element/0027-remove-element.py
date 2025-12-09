class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        seeker , holder = 0 , 0
        count = 0
        while seeker < len(nums):
            if nums[seeker] != val:
                nums[seeker] , nums[holder] = nums[holder] , nums[seeker]
                holder += 1
                count +=1
            seeker += 1
        return count
        

        

    


                
        


      

        