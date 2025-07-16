class Solution(object):
    def freqAlphabets(self, s):
      i = 0
      res = []
      while i < len(s):
         if i + 2 < len(s) and s[i+2] == '#':
            num = int(s[i:i+2])
            res.append(chr(96 + num)) 
            i += 3
         else:
            num = int(s[i])
            res.append(chr(96 + num))
            i += 1

      return "".join(res)
        
   
    