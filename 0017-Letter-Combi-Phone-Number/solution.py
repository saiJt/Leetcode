from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        letter = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        result = []

        def dfs(index: int, path: str):
            if index == len(digits):
                result.append(path)
                return

            for ch in letter[digits[index]]:
                dfs(index + 1, path + ch)

        dfs(0, "")
        return result
