class Solution(object):
    def defangIPaddr(self, address):
        res = ""
        for i in range(len(address)):
            if address[i] == ".":
                res += "[.]"
            else:
                res+= address[i]
        return res


    
      
        