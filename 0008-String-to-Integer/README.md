# String to Integer (atoi) (C, Python, Arithmetic Parsing)

- This function converts a string into a signed 32-bit integer.
- Leading whitespace is ignored, followed by an optional sign (`+` or `-`).
- Digits are parsed sequentially until a non-digit character is encountered.
- If the converted integer exceeds the 32-bit signed integer range  
  \[
  -2^{31} \le x \le 2^{31} - 1
  \]
  the function clamps the result to `INT_MAX` or `INT_MIN`.
- The solution uses **pure arithmetic operations** and prevents overflow
  **before it occurs**.

---

## Core Idea

- The integer value is constructed **digit by digit** using arithmetic:
  - Skip leading whitespace
  - Determine the sign (`+` or `-`)
  - Convert each digit character to its numeric value
  - Append the digit to the result  
    (`result = result * 10 + digit`)

Parsing stops as soon as a non-digit character is encountered.

---

## Key Observation

- Converting a string to an integer is equivalent to:
  - Reading characters sequentially
  - Accumulating digits in base 10
- The sign affects the **final result only**, not intermediate parsing
- In **C**, signed integer overflow results in **undefined behavior**
- Therefore, overflow must be detected **before updating** the result

---

## Algorithm Steps

1. Initialize `result = 0`, `sign = 1`, and index `i = 0`
2. Skip all leading whitespace characters
3. Check for an optional sign (`+` or `-`)
4. While the current character is a digit:
   - Convert the character to a digit
   - Check for overflow **before** updating the result
   - Append the digit to the result
5. Apply the sign and return the final integer
---

## Overflow

- The limits of a signed 32-bit integer are:
  - `INT_MAX = 2147483647`
  - `INT_MIN = -2147483648`

- Before appending a digit, the algorithm checks:

### Overflow Condition

Overflow occurs if:
- `result > INT_MAX / 10`, or
- `result == INT_MAX / 10` and `digit > 7`

If overflow is detected:
- Return `INT_MAX` for positive numbers
- Return `INT_MIN` for negative numbers

This guarantees that the arithmetic operation  
`result * 10 + digit` is **never executed when it would overflow**.

