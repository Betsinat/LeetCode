class Solution(object):
    def toLowerCase(self, s):
        res=""
        for i in range(len(s)):
            if s[i].isupper():
                res += chr(ord(s[i]) + 32)
            else:
                res += s[i]
        return res
        
  
     