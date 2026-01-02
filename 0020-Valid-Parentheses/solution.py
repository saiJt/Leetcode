class Solution:
    def isValid(self, s: str) -> bool:
        if s is None:
            return False

        stack = []

        for c in s:
            if c == '[':
                stack.append(']')
            
            elif c == '{':
                stack.append('}')
            
            elif c == '(':
                stack.append(')')
            
            else:
                if not stack or stack.pop() != c:
                    return False

        
        return not stack
