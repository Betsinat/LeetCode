class Solution(object):
    def commonChars(self, words):
        arr = []
        for i in range(len(words[0])):
             c = words[0][i]
             is_common = True 
             for j in range(1,len(words)):
                if c not in words[j]:
                    is_common = False
                    break
             if is_common:
                arr.append(c)
             for j in range(1,len(words)):
                words[j] = words[j].replace(c , "" , 1)
        return arr
        
            


        
        
        


       
      