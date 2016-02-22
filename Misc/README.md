### THEORY


**Properties of Xor**

**1. Associative**

```bash
(a ^ b) ^ c = a ^ (b ^ c)
```

**2. Commutative**

```bash
a ^ b = b ^ a
```

**3. Self Inverse**



```bash
input ^ mask = output
00    ^ 00   = 00
00    ^ 01   = 01
00    ^ 10   = 10
00    ^ 11   = 11
01    ^ 00   = 01
01    ^ 01   = 00
01    ^ 10   = 11
01    ^ 11   = 10
10    ^ 00   = 10
10    ^ 01   = 11
10    ^ 10   = 00
10    ^ 11   = 01
11    ^ 00   = 11
11    ^ 01   = 10
11    ^ 10   = 01
11    ^ 11   = 00
```

Using the same mask on the output gives us back the input!

```bash
output ^ mask = input
00     ^ 00   = 00
01     ^ 01   = 00
10     ^ 10   = 00
11     ^ 11   = 00
01     ^ 00   = 01
00     ^ 01   = 01
11     ^ 10   = 01
10     ^ 11   = 01
10     ^ 00   = 10
11     ^ 01   = 10
00     ^ 10   = 10
01     ^ 11   = 10
11     ^ 00   = 11
10     ^ 01   = 11
01     ^ 10   = 11
00     ^ 11   = 11
```