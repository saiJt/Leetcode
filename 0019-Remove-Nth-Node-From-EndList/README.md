# Remove Nth Node From End of List (C, Python, Two Pointers)
- This function removes the N-th node from the end of a singly linked list.
- The solution uses a dummy node and two pointers (`fast` and `slow`).
- No new list nodes are created; only pointer connections are updated.
---
## Core Idea
- Use a dummy node to simplify edge cases, especially when the head must be removed.
- Move a `fast` pointer `n` steps ahead to create a fixed distance between `fast` and `slow`.
- Move both pointers together until `fast` reaches the end.
- At that point, `slow` points to the node **right before** the one to be removed.
---
## Key Observation
- The problem asks for the N-th node **from the end**, not from the start.
- Singly linked lists cannot traverse backward, so direct indexing from the end is impossible.
- Maintaining a distance of `n` between two pointers converts a “from the end” problem into a “from the start” position.
- When `fast` reaches `NULL`, `slow` is exactly at the previous node of the target.
---
## Algorithm Steps
1. Create a dummy node and point it to `head`.
2. Initialize `slow` at the dummy node and `fast` at `head`.
3. Move `fast` forward by `n` steps.
4. Move both `fast` and `slow` forward together until `fast` becomes `NULL`.
5. Remove the target node by updating:
   - `slow->next = slow->next->next`
6. Return `dummy->next` as the new head of the list.
---
## Notes
- The dummy node is used only as a fixed reference point and does not belong to the actual list.
- No dynamic allocation is required for traversal pointers (`slow`, `fast`).
### Dummy Node Explanation
In the Python implementation, a dummy node is created using:

```python
dummy = ListNode(0, head)
