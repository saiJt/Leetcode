# Roman to Integer (C, Python, Lookup Table + Scan)
- This function converts a Roman numeral string into an integer.
- Roman numerals are processed from left to right.
- If a smaller value appears before a larger value, it is subtracted.
- Uses a **lookup table** for constant-time character-to-value conversion.
---
## Core Idea
- Each Roman character corresponds to a fixed integer value.
- While scanning the string:
  - If the current value is smaller than the next value, subtract it
  - else, add it
- This reproduces the subtractive rule of Roman numerals.
---
## Key Observation
- Roman numerals follow this rule:
  - A smaller value before a larger value indicates subtraction
    (e.g. IV = 5 − 1, IX = 10 − 1)
- The last character is always added since no next character exists.
- By comparing each character with the next one.
---
## Algorithm Steps
1. Create a lookup table mapping Roman characters to integer values
2. Initialize a running total
3. Traverse the string from left to right
4. If the next character exists and has a larger value:
   - Subtract the current value
5. else:
   - Add the current value
6. Return the final total
