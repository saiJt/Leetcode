# Merge Two Sorted Lists (C, Python, Dummy + Pointer)
- This function merges two sorted singly linked lists into one sorted list.
- The solution uses a **dummy node** and pointer manipulation.
---
## Core Idea
- Use a dummy node to avoid special handling of the head.
- Maintain a `tail` pointer that always points to the last node of the merged list.
- Re-link existing nodes from the input lists instead of creating new ones.
---
## Key Observation
- Both input lists are already sorted.
- At each step, the smaller current node can be safely appended.
- The remaining nodes of a list can be appended directly once the other list is exhausted.
---
## Algorithm Steps
1. Create a dummy node and set `tail` to point to it.
2. While both lists are non-empty:
   - Compare the current nodes of both lists.
   - Append the smaller node to `tail->next`.
   - Advance the pointer of the chosen list.
   - Move `tail` forward.
3. Attach the remaining nodes from the non-empty list.
4. Return `dummy->next` as the head of the merged list.
