# Longest Palindromic Substring (C, Center Expansion)
This function finds the longest palindromic substring in a given string using the center expansion approach.
A palindrome is a string that reads the same forward and backward.
The key idea is to treat each character (and each gap between characters) as a possible center, then expand outward as long as the characters match.

## Core Idea
For every index i in the string:
- Treat i as the center of an odd-length palindrome
- Treat the gap between i and i+1 as the center of an even-length palindrome
- In both cases, expand outward using two pointers (left, right) and stop when:
- The indices go out of bounds, or The characters no longer match

## Key Observation
When the expansion stops:
left and right are one position outside the valid palindrome
Therefore, the actual palindrome range is:
[left + 1 ... right - 1]
and the palindrome length is:
right - left - 1
This formula works for both odd and even palindromes, so no special handling for length is needed.

## Algorithm Steps
1. Get the length of the input string n

2. Initialize:
- maxlen → length of the longest palindrome found so far
- start → starting index of that palindrome

3. For each index i:
- Expand around (i-1, i+1) for odd-length palindromes
- Expand around (i, i+1) for even-length palindromes
- After each expansion, compute the palindrome length using
right - left - 1

4. Update maxlen and start if a longer palindrome is found
- Allocate a new string of size maxlen + 1
- Copy the substring starting at start with length maxlen
- Add the null terminator and return the result

## For the returned substring
- Notes on Memory Management
- The function allocates memory using malloc
- The caller is responsible for calling free() on the returned string
