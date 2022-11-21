class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        indices = {}
        for i in range(len(nums)):
            remaining = target - nums[i]
            if remaining in indices:
                return [i, indices[remaining]]
            indices[nums[i]] = i
        return []

