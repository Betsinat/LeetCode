class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stk = []
        for c in s:
            if c in "({[":
                stk.append(c)
            elif c in "}])":
                if not stk:
                    return False
                top = stk[-1]
                if (c == "}" and top == "{") \
                 or (c == "]" and top =="[") \
                 or (c== ")" and top=="("):
                 stk.pop()
                else:
                    return False
               
        return len(stk) == 0

            
         
   


    
        