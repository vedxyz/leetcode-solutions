class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        maxResult, minPrice = 0, prices[0]
        for price in prices:
            minPrice = min(minPrice, price)
            maxResult = max(maxResult, price - minPrice)
        return maxResult

