# Valid Parentheses (C, Python, Stack)
- This function solves the Valid Parentheses problem.
- The solution is based on stack.
- Expected closing brackets are pushed onto the stack.
- The string is valid only if all brackets match and the stack is empty at the end.
---
## Core Idea
- Use a stack to track brackets that must be closed later.
- Push the **expected closing bracket** when an opening bracket appears.
- When a closing bracket appears, compare it with the stack top.
- The order of brackets is enforced naturally by Stack.
---
## Key Observation
- Brackets must be closed in reverse order of opening.
- Each closing bracket must match the most recent unmatched opening bracket.
- The maximum stack size is bounded by the input string length.
---
## Algorithm Steps
1. Check if the input string is NULL.
2. Initialize a stack and stack pointer.
3. Traverse the string character by character.
4. Push expected closing brackets for opening brackets.
5. On a closing bracket:
   - If the stack is empty, return false.
   - If the top does not match, return false.
   - Otherwise, pop the stack.
6. After traversal, return true only if the stack is empty.
---
# Implementation 1 — Input-sized Stack (VLA)

### Description
- Uses a Variable Length Array (VLA) sized by `strlen(s)`.
- Simple and efficient for competitive programming (C99).
- Avoids heap allocation.
