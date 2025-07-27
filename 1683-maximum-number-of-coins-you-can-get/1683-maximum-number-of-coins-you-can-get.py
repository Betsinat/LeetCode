class Solution(object):
    def maxCoins(self, piles):
        piles.sort(reverse=True)
        total = 0
        n = len(piles) // 3
        idx = 1 
        for _ in range(n):
            total += piles[idx]
            idx += 2  
        return total

