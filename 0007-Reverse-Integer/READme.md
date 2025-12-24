# Reverse Integer (C, Arithmetic Simulation)
- This function reverses a signed 32-bit integer.
- If reversing the integer causes it to overflow the 32-bit signed integer range
[-2^31, 2^31 - 1], the function returns 0.
- The solution uses pure arithmetic operations instead of converting the integer to a string, and carefully prevents overflow before it occurs.

## Core Idea
- The integer is reversed digit by digit using arithmetic operations:
  - Extract the last digit using modulo (x % 10)
  - Remove the last digit using integer division (x /= 10)
  -Append the digit to the reversed number (result = result * 10 + digit)

This process continues until the original number becomes zero.

## Key Observation
- Reversing an integer is equivalent to repeatedly:
  -Taking the last digit
  -Shifting the current result left by one decimal place
-In C, integer overflow results in undefined behavior
-Therefore, overflow must be detected before updating the result

## Overflow Handling (Critical Detail)
-The limits of a signed 32-bit integer are:
  -INT_MAX = 2147483647
  -INT_MIN = -2147483648
-Before appending a digit, the algorithm checks:
### Positive Overflow
  -result > INT_MAX / 10
  -result == INT_MAX / 10 and digit > 7
### Negative Overflow
  -result < INT_MIN / 10
  -result == INT_MIN / 10 and digit < -8

If any of these conditions are met, reversing the integer would exceed the valid range, and the function immediately returns 0.


## Algorithm Steps
1.Initialize result to 0
2.While the input integer is not zero:
  -Extract the last digit using modulo
  -Remove the last digit using integer division
  -Check for overflow before updating the result
  -Append the digit to the result
3. Return the reversed integer if no overflow occurs


## Why <limits.h> Is Used
- The C standard does not guarantee that int is always 32-bit.
-Using INT_MAX and INT_MIN from <limits.h> ensures:
  -Correct overflow boundaries
  - No hardcoded magic numbers
  - Avoidance of undefined behavior
