class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return [""]

        result = []
        current = []
        open_p = 0
        close_p = 0

        def dfs(result, current, open_p, close_p, n):
            if len(current) == 2*n:
                result.append("".join(current))
                return

            if open_p < n:
                current.append('(')
                open_p += 1
                dfs(result, current, open_p, close_p, n)
                open_p -= 1
                current.pop()

            if open_p > close_p:
                current.append(')')
                close_p += 1
                dfs(result, current, open_p, close_p, n)
                close_p -= 1
                current.pop()
                
        dfs(result, current, open_p, close_p, n)

        return result
