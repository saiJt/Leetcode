class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x % 10 == 0 and x != 0: return False
        if x < 0: return False

        reverse = 0

        while x > reverse:
            reverse = reverse * 10 + x % 10
            x //= 10

        return reverse == x or reverse // 10 == x
