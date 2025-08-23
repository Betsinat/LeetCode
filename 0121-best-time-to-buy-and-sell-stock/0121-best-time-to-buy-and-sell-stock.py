class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """    
        min_price = prices[0]
        max_profit = 0
        for i in range(1 , len(prices)):
            if prices[i] < min_price:
                min_price = prices[i]
            else:
                diff = prices[i] - min_price
                if diff > max_profit:
                    max_profit = diff
        return max_profit