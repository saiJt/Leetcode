# Find the Index of the First Occurrence in a String (C, Python, KMP)
- The solution is based on the Knuth–Morris–Pratt (KMP) algorithm, which avoids redundant character comparisons.
- The algorithm is designed to be efficient and easy to reason about by separating preprocessing and searching.
---
## Core Idea
- Preprocess the pattern string (`needle`) to build an LPS (Longest Prefix Suffix) array.
- Use the LPS array as a reference to determine how far the pattern index can fall back on a mismatch.
- Previously matched prefix information is reused instead of restarting comparisons.
---
## Key Observation
- The text index (`haystack`) never moves backward during the search.
- On a mismatch after partial matches, the pattern index is updated using `lps[j - 1]` rather than resetting to zero.
- The search terminates as soon as the pattern index reaches the length of `needle`, indicating a full match.
---
## Algorithm Steps
1. If the pattern string (`needle`) is empty, return `0`.
2. Build the LPS array using only the pattern string to encode prefix–suffix relationships.
3. Traverse the text string (`haystack`) while comparing characters with the pattern.
4. On a match, advance both indices; on a mismatch, update the pattern index using the LPS array.
5. When the entire pattern is matched, return the starting index of the match; otherwise, return `-1`.
---
## KMP Summary
- KMP (Knuth–Morris–Pratt) is a string matching algorithm that avoids re-checking characters.
- It preprocesses the pattern string into an LPS (Longest Prefix Suffix) array.
- The LPS array determines how far the pattern index can safely fall back on a mismatch.
- During the search, the text index never moves backward.
