class Solution(object):
    def numJewelsInStones(self, jewels, stones):
     b = Counter(stones)
     count = 0
     for char in jewels:
        count += b[char]
     return count
    

        
      