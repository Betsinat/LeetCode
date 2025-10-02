class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        # initalizing the first window
        window_sum = sum(arr[:k])
        tot = 0
        # checking the first subarry
        if  window_sum / k >= threshold:
            tot += 1
        for end in range(k, len(arr)):
             window_sum += arr[end]
             window_sum -= arr[end - k]
             if  window_sum / k >= threshold:
                tot += 1
               
        return tot



        