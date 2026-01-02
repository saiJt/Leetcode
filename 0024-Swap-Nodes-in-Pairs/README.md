# Swap Nodes in Pairs (C,Python, Linked List)
- This problem swaps every two adjacent nodes in a singly linked list.
- The solution is implemented iteratively and focuses on **pointer manipulation**, not value swapping.
---
## Core Idea
- The linked list is processed **two nodes at a time**.
- For each adjacent pair `(A, B)`, the goal is to rearrange pointers so that `B` comes before `A`.
- Instead of modifying node values, the algorithm rewires the `next` pointers.
---
## Key Observation
- A swap is only possible when **two consecutive nodes exist**.
- Swapping affects not only the two nodes, but also the node **before the pair**.
- The head of the list may change after the first swap.
---
## Algorithm
1. Create a dummy node and connect it to the head of the list.
2. Initialize a pointer `prev` to the dummy node.
3. While there are at least two nodes after `prev`:
   - Let `A = prev->next`
   - Let `B = A->next`
   - Store `next = B->next`
4. Swap the pair by reconnecting pointers so that `B` comes before `A`.
5. Move `prev` to `A`, the end of the swapped pair.
6. Repeat until fewer than two nodes remain.
7. Return `dummy->next` as the new head of the list.
