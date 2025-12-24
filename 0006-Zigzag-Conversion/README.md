# Zigzag Conversion (C, Row Simulation)
This function converts a string into a zigzag pattern on a given number of rows and then reads the result line by line.
Instead of building the actual zigzag grid, the algorithm simulates the row movement and stores characters directly into row-based buffers.

## Core Idea
The zigzag pattern follows a repeating movement:
- Move downward from row 0 to row numRows - 1
- Then move upward from row numRows - 1 back to row 0
- Repeat this process until all characters are placed
Each row is treated as an independent string buffer.

### Key Observation
- Each character belongs to exactly one row
- The zigzag pattern can be simulated using:
  - row → current row index
  - direction → whether we are moving down or up
- Direction only changes when we reach:
  - The top row (row == 0)
  - The bottom row (row == numRows - 1)
No 2D matrix is required.

### Algorithm Steps
1. Handle the edge case:
- If numRows == 1, return the original string directly
2. Initialize:
- An array of string buffers, one for each row
- An array rowLen to track the current length of each row
- Variables row and direction to control zigzag movement
3. Iterate through each character in the input string:
- Append the character to the current row buffer
- Move the row index up or down depending on the direction
- Reverse direction when the top or bottom row is reached
4. After all characters are placed:
- Null-terminate each row buffer
- Concatenate all row buffers from top to bottom into a single result string
5. Return the final converted string

### Notes on Memory Management
- Memory for row buffers and the result string is allocated using malloc
- Each row buffer is freed after constructing the final result
- The caller is responsible for calling free() on the returned string
