class Solution(object):
    def similarPairs(self, words):
        count = 0
        for i in range(len(words)):
            common = Counter(words[i])          
            for j in range(i + 1, len(words)):  
                current = Counter(words[j])     
                if common.keys() == current.keys():  
                    count += 1
        return count



               
               
            



    
            
        


        
   