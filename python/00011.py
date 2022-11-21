class Solution:
    def maxArea(self, height: list[int]) -> int:
        maxResult = 0
        l, r = 0, len(height) - 1
        while l < r:
            maxResult = max(maxResult, (r - l) * min(height[l], height[r]))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return maxResult

