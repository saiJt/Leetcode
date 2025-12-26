class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        i = 0
        symbol = 1
        result = 0
        n = len(s)


        while i < n and s[i] == ' ':
            i += 1

        if i < n and s[i] == '-':
            symbol = -1
            i += 1

        elif i < n and s[i] == '+':
            i = i+1

        while i < n and '0' <= s[i] <= '9':
            digit = ord(s[i]) - ord('0')

            if result > INT_MAX // 10 or (result == INT_MAX // 10 and digit > 7 ):
                return INT_MAX if symbol == 1 else INT_MIN

            result = result * 10 + digit
            i += 1
        

        return result * symbol
