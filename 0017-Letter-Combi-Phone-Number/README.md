# Letter Combinations of a Phone Number (Python, Backtracking)
- The algorithm incrementally builds letter strings by processing digits from left to right.
---
## Core Idea
- Each digit maps to a fixed set of letters (phone keypad).
- We choose one letter per digit and build combinations step by step.
- A recursive explores all valid choices until a full combination is formed.
---
## Key Observation
- The order of digits is fixed, but each digit has multiple letter choices.
- A combination is complete when its length equals the number of digits.
- Only fully constructed strings should be added to the result.
---
## Algorithm Steps
1. Return an empty list if the input string is empty.
2. Define a mapping from digits (`2`–`9`) to their corresponding letters.
3. Use a recursive function with parameters `(index, path)`.
4. If `index == len(digits)`, append `path` to the result list.
5. Otherwise, iterate over all letters mapped from `digits[index]` and recurse.
6. Start DFS from index `0` with an empty path.
7. Return the result list after DFS completes.
