# 3Sum (C, Python, Two Pointer)
- This function solves the 3Sum problem.
- The solution is based on sorting the array and using the two-pointer technique.
- The algorithm avoids duplicates by carefully skipping repeated values.
- All edge cases required by the LeetCode C interface are handled explicitly.
---
## Core Idea
- Sort the input array first.
- Fix one element `nums[i]` and find two other elements using two pointers.
- Use the sorted order to move pointers efficiently based on the current sum.
- Store only unique triplets whose sum is zero.
---
## Key Observation
- After sorting, increasing `left` increases the sum and decreasing `right` decreases the sum.
- Duplicate triplets occur if the same value is reused at the same pointer position.
- To avoid duplicates:
  - Skip repeated values for index `i`.
  - After finding a valid triplet, skip repeated values for `left` and `right`.
- Each valid triplet always has exactly three elements.
---
## Algorithm Steps
1. Sort the input array using `qsort`.
2. Iterate index `i` from `0` to `numsSize - 3`.
3. Skip the iteration if `nums[i]` is the same as the previous value.
4. Initialize two pointers:
   - `left = i + 1`
   - `right = numsSize - 1`
5. While `left < right`:
   - Compute `sum = nums[i] + nums[left] + nums[right]`
   - If `sum < 0`, increment `left`
   - If `sum > 0`, decrement `right`
   - If `sum == 0`:
     - Store the triplet `{nums[i], nums[left], nums[right]}`
     - Move both pointers inward
     - Skip duplicate values for `left` and `right`
6. Update `returnSize` and `returnColumnSizes` as required by the C interface.
7. Return the dynamically allocated result array.
