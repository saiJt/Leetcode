##Longest Substring Without Repeating Characters (C, Sliding Window)
This function finds the length of the longest substring without repeating characters in a given string.

###Approach
Use the sliding window technique with two pointers.
Maintain a frequency array to track characters in the current window.
Expand the window by moving the right pointer.
If a duplicate character appears, shrink the window from the left.
Ensure the window always contains unique characters.
Track and update the maximum window length.

####Key Details
Use two pointers (left and right) to represent the current substring window.
Use a fixed-size array (seen[256]) to store character frequencies.
Increment the count when a character enters the window.
Decrement the count when a character leaves the window.
Use a while loop to remove duplicates until the window becomes valid.
Cast characters to unsigned char for safe array indexing in C.
