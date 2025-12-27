# Container With Most Water (C, Two Pointers Technique)
- This function determines the maximum amount of water that can be stored
  between two vertical lines.
- Each index represents a vertical line, and its value represents the height.
- The container cannot be slanted, so the water height is limited by the
  shorter line.
- Uses the **Two Pointers** technique to achieve linear time complexity.
---
## Core Idea
- The amount of water depends on:
  - The **distance** between two lines
  - The **minimum height** of the two lines
- Formula:
area = min(height[left], height[right]) × (right − left)
- Instead of checking all pairs, two pointers are used to efficiently find
the maximum area.
---
## Key Observation
- The water height is always determined by the **shorter line**
- Moving the taller line inward:
- Decreases the width
- Does not increase the height
- Cannot produce a larger area
- Moving the shorter line may increase the height and lead to a larger area
- Therefore, always move the pointer at the **shorter height**
---
## Algorithm Steps
1. Initialize two pointers at both ends of the array
2. Compute the area using the current two lines
3. Update the maximum area if the current area is larger
4. Move the pointer pointing to the shorter line
5. Repeat until the two pointers meet
