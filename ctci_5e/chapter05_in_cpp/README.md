## Chapter 5- Bit Manipulation

### EXERCISES

**5_1** You  are given two 32-bit numbers, **N** and **M**, and two bit positions, `i` and `j`  Write a  method to set all bits between `i` and `j` in **N** equal to **M** (eg, **M** becomes a substring of **N** located at `i` and starting at `j`).

EXAMPLE:
```
Input: N = 10000000000, M = 10101, i = 2, j = 6 Output: N = 10001010100
```
**5_2** Given a (decimal - eg, 3.72) number that is passed in as a string, print the binary representation. If the number cannot be represented accurately in binary, print “`ERROR`”

**5_3** Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary  representation.

**5_4** Explain what the following code does: 
```
((n & (n-1)) == 0).
```

**5_5** Write a function to determine the number of bits required to convert integer A to  integer B.
```
Input: 31, 14
Output: 2
```

**5_6** Write a program to swap odd and even bits in an integer with as few instructions as possible (e g , bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).

**5_7** An array `A[1..n]` contains all the integers from 0 to n except for one number which is missing In this problem, we cannot access an entire integer in A with a single operation The elements of A are represented in binary, and the only operation we can use to access them is “fetch the jth bit of `A[i]`”, which takes constant time Write code to find the missing integer. Can you do it in `O(n)` time?



### THEORY

**And (`&`):**
```bash
0 & 0 = 0
1 & 0 = 0
0 & 1 = 0
1 & 1 = 1

x & 0 = 0
x & 1 = x
```

**Or (`|`):**
```bash
0 | 0 = 0
1 | 0 = 1
0 | 1 = 1
1 | 1 = 1

x | 0 = x
x | 1 = 1
```

**Xor (`^`):**
```bash
0 ^ 0 = 0
1 ^ 0 = 1
0 ^ 1 = 1
1 ^ 1 = 0

x ^ 0 = x
x ^ 1 = ~x
```

**Left Shift:**
`x << y` means `x` shifted `y` bits to the left. If you start shifting and you run out of space, the bits just “drop off”. For example:
```bash
00011001 << 2 = 01100100
00011001 << 4 = 10010000
```

**Right Shift:**
`x >> y` means `x` shifted `y` bits to the right. If you start shifting and you run out of space, the bits just “drop off” the end. Example:
```bash
00011001 >> 2 = 00000110
00011001 >> 4 = 00000001
```

### **5_2** Converting Floating-Point Numbers from Decimal to Binary

Example: converting the decimal value **.625** to a binary representation.

**Step 1**: Begin with the decimal fraction and multiply by 2. The whole number part of the result is the first binary digit to the right of the point.

Because .625 x 2 = 1.25, the first binary digit to the right of the point is a 1. So far, we have .625 = .1??? . . . (base 2) .

**Step 2**: Next we disregard the whole number part of the previous result (the 1 in this case) and multiply by 2 once again. The whole number part of this new result is the *second* binary digit to the right of the point. We will continue this process until we get a zero as our decimal part or until we recognize an infinite repeating pattern.

Because .25 x 2 = 0.50, the second binary digit to the right of the point is a 0. So far, we have .625 = .10?? . . . (base 2) .

**Step 3**: Disregarding the whole number part of the previous result (this result was

.50 so there actually is no whole number part to disregard in this case), we multiply by 2 once again. The whole number part of the result is now the next binary digit to the right of the point.

Because .50 x 2 = 1.00, the third binary digit to the right of the point is a 1. So now we have .625 = .101?? . . . (base 2) .

**Step 4**: In fact, we do not need a Step 4. We are finished in Step 3, because we had 0 as the fractional part of our result there.

Hence the representation of .625 = .101 (base 2) .


### **5_3** Finding next smaller/ larger number with same number of set bits

Let say we have a bit pattern such as

`111100111` - representing `487` in decimal

Remember that we need to preserve the number of **0**s and **1**s as in the input

**Larger number**

**Step 1**: Find the first `0` bit from the right of the input that is followed by `1`, i.e. `01`

**Step 2**: Toggle this bit to a `1`. 

**Step 3**: Since the number of **1**s is +1 now, reduce the number of **1**s on the right of this flip point by 1 to compensate.

`01` becomes `10`

The new bit pattern will become `111101011` - `491` in decimal (we have preserved the no of bits set and not set as per the input)