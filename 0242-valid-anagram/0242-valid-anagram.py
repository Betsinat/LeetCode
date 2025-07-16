class Solution(object):
    def isAnagram(self, s, t):
     if len(s) != len(t):
        return False
     if sorted(s) == sorted(t):
         return True
     else:
         return False
 