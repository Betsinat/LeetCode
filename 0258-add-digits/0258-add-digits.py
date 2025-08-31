class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        n = str(num)
        while len(n) > 1:
                res = sum(int(x) for x in n)
                n = str(res)
        return int(n)
            
            
                
        

        