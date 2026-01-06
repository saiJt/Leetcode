class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # overflow guard
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1

        divid = abs(dividend)
        divis = abs(divisor)

        ans = 0

        while divid >= divis:
            tmp = divis
            multiple = 1

            while (tmp << 1) <= divid:
                tmp <<= 1
                multiple <<= 1

            divid -= tmp
            ans += multiple

        if divisor < 0 and dividend < 0: 
            return ans
        elif divisor < 0 or dividend < 0: 
            ans = -ans

        return ans
