# Generate Parentheses (C, Python, Backtracking)
- This function generates all combinations of well-formed parentheses.
- The solution is based on DFS with backtracking while maintaining valid parentheses constraints.
---
## Core Idea
- Build the parentheses string character by character using Depth-First Search (DFS).
- Track how many opening and closing parentheses have been used.
- Only allow choices that keep the parentheses string valid.
- When the string reaches length `2 * n`, store it as a completed result.
---
## Key Observation
- A closing parenthesis `')'` can only be added if there are more opening parentheses `'('` already used.
- The number of opening parentheses cannot exceed `n`.
---
## Algorithm Steps
1. Allocate a temporary character array `current` of size `2 * n + 1`.
2. Use DFS to fill `current` from left to right using an index `idx`.
3. If `open < n`, place `'('` at `current[idx]` and recurse.
4. If `close < open`, place `')'` at `current[idx]` and recurse.
5. When `idx == 2 * n`, copy `current` into newly allocated memory and store it in `result`.
6. Continue until all valid combinations are generated.
## Backtracking (Brief Explanation)
- Backtracking means **making a choice, exploring deeper, then trying a different choice**.
- In this problem, each position can choose `'('` or `')'` if it keeps the parentheses valid.
- The DFS explores all valid paths by moving forward and returning automatically when recursion ends.
- In C, backtracking is achieved by **overwriting characters using an index**, not by removing elements.
---
#### Why `(char**)malloc(...)` Is Used
- The final output is an **array of strings**.
- Each string is of type `char*`.
- Therefore, the result container must be of type `char**` (array of `char*`).
- Casting `(char**)` explicitly indicates that the allocated memory stores string pointers.
- This also ensures compatibility with C++ compilers, where such casting is required.
