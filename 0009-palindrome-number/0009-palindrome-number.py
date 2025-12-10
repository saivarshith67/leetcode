class Solution:
    def isPalindrome(self, x: int) -> bool:
        val = list(str(x))
        return val == val[::-1]