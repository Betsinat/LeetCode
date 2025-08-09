class Solution(object):
    def similarPairs(self, words):
        arr = ["".join(sorted(set(s))) for s in words]
        freq = Counter(arr)
        pairs = 0
        for s , c in freq.items():
            pairs += c * (c - 1)// 2
        return pairs

            
            
        


        
   