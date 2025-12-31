# 3Sum Closest (C, Python, Two Pointers)
- This function solves the 3Sum Closest problem/
- The solution is based on sorting the array and applying the two-pointer technique.
- The algorithm runs in O(n²) time and uses constant extra space.
- Exact matches are handled with an early return for efficiency.
---
## Core Idea
- Sort the array to enable ordered traversal.
- Fix one element and use two pointers to explore remaining pairs.
- Maintain a running best sum that is closest to the target.
- Update the best sum greedily based on absolute difference.
---
## Key Observation
- After sorting, increasing the left pointer increases the sum, while decreasing the right pointer decreases the sum.
- The closest sum can be tracked by comparing `abs(target - current_sum)`.
- If `current_sum == target`, it is the optimal answer and the algorithm can stop immediately.
---
## Algorithm Steps
1. Sort the input array.
2. Initialize the best sum using the first three elements.
3. Iterate through the array, fixing one index at a time.
4. Use two pointers (`left`, `right`) to evaluate possible sums.
5. Update the best sum when a closer value is found and adjust pointers based on comparison with the target.
6. Return the best sum after traversal completes.
---
## Sorting with qsort
- The C standard library function `qsort` is used to sort the array.
- Since `qsort` is a generic sorting function, it requires a comparator that operates on `void*`.

### Comparator Function
```c
int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}
