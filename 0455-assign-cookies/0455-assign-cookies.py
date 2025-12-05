class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        # scanning the whole children gridness , and scanning the size cookie
        #if the cookie can satsfy the child and not taken give him o(n*m)

        g.sort()
        s.sort()
        #childern
        i = 0
        #cookie 
        j = 0
        satsfied_childrens = 0
        while i < len(g) and j < len(s):
           if s[j] >= g [i]:
              satsfied_childrens +=1
              i +=1
              j +=1
           else:
              j +=1
        return satsfied_childrens

    

        
