class Solution(object):
    def toLowerCase(self, s):
        res=""
        for i in range(len(s)):
            if s[i].isupper():
                res += s[i].lower()
            else:
                res += s[i]
        return res

     