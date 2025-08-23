class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        '''min_price = prices[0]
        max_profit = 0
        for i in range(1 , len(prices)):
            if prices[i] > min_price:
                max_profit += prices[i] - min_price
                min_price = prices[i]
            else:
                min_price = prices[i]
        return max_profit '''
        max_profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                max_profit += prices[i] - prices[i-1]
        return max_profit


        