# Add Two Numbers (C, Linked List)

This function adds two numbers represented as reversed singly linked lists.
Each node contains a single digit, and the digits are stored in reverse order.

## Approach
- Use a dummy node to simplify head management.
- Use a tail pointer to efficiently append new nodes.
- Traverse both lists digit by digit.
- Maintain a carry value across iterations.
- Treat missing digits as 0.
- Append a final node if a carry remains.
