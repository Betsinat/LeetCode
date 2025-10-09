class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        left , max_count , count = 0 , 0 , 0
        vowel = ["a" , "e" , "i" , "o" , "u"]
        for r in range(len(s)):
            count +=1 if s[r] in vowel else 0
            if r - left + 1 > k:
                count -= 1 if s[left] in vowel else 0
                left += 1
            max_count = max(count ,  max_count)
        return max_count
