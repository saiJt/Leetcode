# 4Sum (C, Python, Two Pointers + Sorting)
- This function solves the 4Sum problem.
- The solution is based on fixing two indices and using two pointers for the remaining two values.
---
## Core Idea
- Sort the array to enable two-pointer traversal.
- Fix two indices `i` and `j` using nested loops.
- For each fixed pair `(i, j)`, use two pointers `left` and `right` to find pairs that complete the target sum.
- Store only exact matches and skip all duplicate combinations.
---
## Key Observation
- After sorting, if the current sum is smaller than the target, moving `left` rightward increases the sum.
- If the current sum is larger than the target, moving `right` leftward decreases the sum.
- For a fixed `i`, duplicate values of `j` must be skipped **only within the same `i` scope**.
- Duplicate values for `left` and `right` are skipped after a valid quadruplet is found to avoid repeated results.
---
## Algorithm Steps
1. Sort the input array using `qsort`.
2. Iterate index `i` from `0` to `numsSize - 4`, skipping duplicate values.
3. For each `i`, iterate index `j` from `i + 1` to `numsSize - 3`, skipping duplicates within the same `i`.
4. Initialize two pointers:
   - `left = j + 1`
   - `right = numsSize - 1`
5. While `left < right`:
   - Compute the sum of the four values.
   - If the sum is smaller than `target`, increment `left`.
   - If the sum is larger than `target`, decrement `right`.
   - If the sum equals `target`:
     - Store the quadruplet.
     - Move both pointers and skip duplicate values.
6. Dynamically expand the result array when capacity is reached.
7. Return all unique quadruplets along with their column sizes.
---
## Why `long` Is Used for the Sum
- Each value in `nums` is an `int`, but adding four `int` values can exceed the 32-bit integer range.
- Integer overflow leads to undefined behavior in C and may cause incorrect comparisons with `target`.
- Casting the sum to `long` ensures the addition is performed in a wider integer type.
- This guarantees correctness even when input values are close to `INT_MAX` or `INT_MIN`.
