# Integer to Roman (C, Python, Greedy with Lookup Table)
- This function converts an integer into a Roman numeral.
- Roman numerals are constructed by appending symbols from the highest value
  to the lowest value.
- Subtractive forms (IV, IX, XL, XC, CD, CM) are handled explicitly.
- Uses a **greedy strategy** with a lookup table for clarity and efficiency.
---
## Core Idea
- Roman numeral conversion is based on repeatedly subtracting the **largest
  possible value** from the number.
- Each subtraction appends the corresponding Roman symbol to the result.
- Both normal and subtractive forms are treated uniformly as data.
---
## Key Observation
- Roman numerals follow a **greedy structure**:
  - Always consume the largest valid symbol first
- Subtractive cases (4, 9, 40, 90, 400, 900) are not special logic,
  but predefined symbol-value pairs.
- By ordering values from largest to smallest, all rules are naturally enforced.
---
## Algorithm Steps
1. Define arrays of Roman values and corresponding symbols in descending order
2. Initialize a result buffer and a write pointer
3. While the input number is greater than 0:
   - Append the symbol while its value can be subtracted
   - Subtract the value from the number
4. Null-terminate the result string
5. Return the result
