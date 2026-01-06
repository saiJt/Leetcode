# Divide Two Integers (C, Python, Bit Manipulation)
- This function solves the integer division problem without using multiplication, division, or modulo operators.
- The solution is based on repeated subtraction using bit shifting to speed up the process.
- The algorithm performs division by subtracting the largest possible power-of-two multiple of the divisor at each step.
---
## Core Idea
- Perform integer division by repeatedly subtracting the divisor from the dividend.
- Instead of subtracting the divisor one by one, double the divisor using left bit shifts to subtract large chunks at once.
- At each step, subtract the largest shifted divisor that does not exceed the remaining dividend.
---
## Key Observation
- Left shifting an integer by one bit is equivalent to multiplying it by 2.
- The divisor can be expressed as `divisor × 2^k`, allowing the quotient to be built from powers of two.
- The process continues until the remaining dividend is smaller than the divisor.
---
## Algorithm Steps
1. Handle the overflow case when the dividend is `INT_MIN` and the divisor is `-1`.
2. Convert both dividend and divisor to positive values using a larger integer type to avoid overflow.
3. While the remaining dividend is greater than or equal to the divisor:
   - Initialize a temporary divisor and a multiplier.
   - Repeatedly left-shift the temporary divisor until it exceeds the remaining dividend.
   - Subtract the largest valid shifted divisor from the dividend.
   - Add the corresponding multiplier to the result.
4. Apply the correct sign to the final result.
5. Return the computed quotient.
