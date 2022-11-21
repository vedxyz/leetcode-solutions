class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0: return False
        
        reverse, xtemp = 0, x
        while xtemp:
            xtemp, remainder = divmod(xtemp, 10)
            reverse = reverse * 10 + remainder
        return reverse == x

