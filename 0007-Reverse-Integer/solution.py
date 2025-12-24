class Solution:
    def reverse(self, x: int) -> int:
        int_max = 2**31 -1

        result = 0
        digit = 0
        neg = 0

        if x < 0:
            neg = 1
            x = abs(x)
        
        while x != 0:
            digit = x % 10
            x //= 10

            # overflow check
            if result > int_max // 10 or (result == int_max // 10 and digit > 7):
                return 0
                
            result = result * 10 + digit

        if neg:
            result = -result

        return result
