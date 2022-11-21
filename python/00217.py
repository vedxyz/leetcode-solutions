class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        contained = set()
        for num in nums:
            if num in contained:
                return True
            contained.add(num)
        return False

