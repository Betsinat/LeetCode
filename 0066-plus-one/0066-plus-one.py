class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        res = []
        dig = ""
        for i in range(len(digits)):
            dig += str(digits[i])
        b = int(dig) + 1
        c = str(b)
        for i in range(len(c)):
            res.append(int(c[i]))
        return res

