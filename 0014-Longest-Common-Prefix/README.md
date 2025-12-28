# Longest Common Prefix (C, Character Scan)
- This function finds the longest common prefix among an array of strings.
- Strings are compared character by character using index-based scanning.
- If a mismatch occurs or a string ends, the prefix terminates immediately.
- The solution uses the first string as a reference to avoid extra memory allocation.

---

## Core Idea
- The longest common prefix cannot be longer than the first string.
- Use the first string as a baseline and compare each character index across all strings.
- Once a mismatch is found, the prefix ends at that position.

---

## Key Observation
- All strings must share the same character at index `i` for the prefix to continue.
- If any string:
  - ends at index `i`, or
  - has a different character at index `i`
  
  then the common prefix stops.
- In C, inserting `'\0'` terminates a string, allowing the prefix to be trimmed efficiently.

---

## Algorithm Steps
1. If the input array is empty, return an empty string
2. Use the first string as the reference prefix
3. Iterate through each character index `i` of the first string
4. For every other string:
   - If the string ends at index `i`, stop
   - If the character at index `i` differs, stop
5. Insert `'\0'` at the stopping index
6. Return the modified first string as the result
