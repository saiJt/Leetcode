# Palindrome Number (C, Half-Reversal Technique)
- This function determines whether a given integer is a palindrome.
- A palindrome number reads the same forward and backward.
- Negative numbers and numbers ending with `0` (except `0` itself) are not palindromes.
- Only **half of the number is reversed**, preventing unnecessary computation
  and avoiding overflow.
---
## Core Idea
- A palindrome can be checked by comparing the **left half** and **right half**
  of the number.
- Algorithm:
  - Reverses the **last half** of the digits
  - Compares it with the **remaining first half**
This avoids reversing the entire number.
---
## Key Observation
- Negative numbers cannot be palindromes
- If a number ends with `0` and is not `0`, it cannot be a palindrome
- During each iteration:
  - One digit is removed from the right side of `x`
  - One digit is appended to `reversedHalf`
- When `reversedHalf` becomes **greater than or equal to** `x`,
  half of the digits have been processed
This naturally distinguishes between even-length and odd-length numbers.
---
## Algorithm Steps
1. If `x < 0`, return `false`
2. If `x % 10 == 0` and `x != 0`, return `false`
3. Initialize `reversedHalf = 0`
4. While `x > reversedHalf`:
   - Remove the last digit from `x`
   - Append the digit to `reversedHalf`
5. If `reversedHalf > x`, remove the middle digit (`reversedHalf /= 10`)
6. Return whether `x == reversedHalf`
