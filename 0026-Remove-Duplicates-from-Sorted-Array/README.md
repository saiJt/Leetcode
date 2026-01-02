# Remove Duplicates from Sorted Array (C, Python, Two Pointer)
- This function removes duplicates from a sorted array **in-place**.
- The solution uses the **Two Pointers** technique to track read and write positions.
- The function returns the number of unique elements.
---
## Core Idea
- Since the array is sorted, duplicate values appear **consecutively**.
- We scan the array once and overwrite positions only when a new value is found.
- The front part of the array is reused to store unique elements.
- The remaining elements after the returned length are ignored.
---
## Key Observation
- We must distinguish between:
  - **read pointer (`i`)**: scans every element
  - **write pointer (`idx`)**: marks the position of the last unique element
- At any time, the invariant is:
  - `nums[0 : idx + 1]` contains only unique elements
- The value to copy is always `nums[i]`, because:
  - `i` represents the **current element being inspected**
  - `nums[i+1]` has not been checked yet and must not be used
---
## Algorithm Steps
1. Initialize `idx = 0` (first element is always unique).
2. Iterate through the array using `i` as the read pointer.
3. Compare `nums[i]` with the last unique value `nums[idx]`.
4. If they are different:
   - Increment `idx`
   - Copy `nums[i]` to `nums[idx]`
5. After the loop, return `idx + 1` as the number of unique elements.
