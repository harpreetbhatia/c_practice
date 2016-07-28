#include <stdlib.h>
#include <stdio.h>

	IEEE Standard 754 floating point is the most common representation today for real numbers on computers, including Intel-based PC's, Macintoshes, and most Unix platforms.
	IEEE floating point numbers have three basic components: the sign, the exponent, and the mantissa. The mantissa is composed of the fraction and an implicit leading digit (explained below). The exponent base(2) is implicit and need not be stored.
	The following figure shows the layout for single (32-bit) and double (64-bit) precision floating-point values. The number of bits for each field are shown (bit ranges are in square brackets):
	Sign   Exponent   Fraction  Bias
	--------------------------------------------------
	Single Precision 1 [31] 8 [30-23]  23 [22-00] 127
	 
	Double Precision 1 [63] 11 [62-52] 52 [51-00] 1023
	The sign bit is as simple as it gets. 0 denotes a positive number; 1 denotes a negative number. Flipping the value of this bit flips the sign of the number.
	The exponent field needs to represent both positive and negative exponents. To do this, a bias is added to the actual exponent in order to get the stored exponent. For IEEE single- precision floats, this value is 127. Thus, an exponent of zero means that 127 is stored in the exponent field. A stored value of 200 indicates an exponent of (200-127), or 73. For reasons discussed later, exponents of -127 (all 0s) and +128 (all 1s) are reserved for special numbers. For double precision, the exponent field is 11 bits, and has a bias of 1023.
	The mantissa, also known as the significand, represents the precision bits of the number. It is composed of an implicit leading bit and the fraction bits. To find out the value of the implicit leading bit, consider that any number can be expressed in scientific notation in many different ways. For example, the number five can be represented as any of these:
	5.00 × 100
	0.05 × 10 ^ 2
	5000 × 10 ^ -3
	In order to maximize the quantity of representable numbers, floating-point numbers are typically stored in normalized form. This basically puts the radix point after the first non- zero digit. In normalized form, five is represented as 5.0 × 100. A nice little optimization is available to us in base two, since the only possible non-zero digit is 1. Thus, we can just assume a leading digit of 1, and don't need to represent it explicitly. As a result, the mantissa has effectively 24 bits of resolution, by way of 23 fraction bits.
	So, to sum up:
	1.	The sign bit is 0 for positive, 1 for negative.
	2.	The exponent's base is two.
	3.	The exponent field contains 127 plus the true exponent for single-precision, or 1023 plus the true exponent for double precision.
	4.	The first bit of the mantissa is typically assumed to be 1.f, where f is the field of fraction bits.
	C Structures
	191.Can structures be assigned to variables and passed to and from functions?
	Yes, they can!
	But note that when structures are passed, returned or assigned, the copying is done only at
	 
	one level (The data pointed to by any pointer fields is not copied!. 192.Can we directly compare two structures using the == operator? No, you cannot!
	The only way to compare two structures is to write your own function that compares the structures field by field. Also, the comparison should be only on fields that contain data (You would not want to compare the next fields of each structure!).
	A byte by byte comparison (say using memcmp()) will also fail. This is because the comparison might fonder on random bits present in unused "holes" in the structure (padding used to keep the alignment of the later fields correct). So a memcmp() of the two structure will almost never work. Also, any strings inside the strucutres must be compared using strcmp() for similar reasons.
	There is also a very good reason why structures can be compared directly - unions!. It is because of unions that structures cannot be compared for equality. The possibility that a structure might contain a union makes it hard to compare such structures; the compiler can't tell what the union currently contains and so wouldn't know how to compare the structures. This sounds a bit hard to swallow and isn't 100% true, most structures don't contain unions, but there is also a philosophical issue at stake about just what is meant by "equality" when applied to structures. Anyhow, the union business gives the Standard a good excuse to avoid the issue by not supporting structure comparison.
	If your structures dont have stuff like floating point numbers, pointers, unions etc..., then you could possibly do a memset() before using the structure variables..
	memset (&myStruct, 0, sizeof(myStruct));
	This will set the whole structure (including the padding) to all-bits-zero. We can then do a memcmp() on two such structures.
	memcmp (&s1,&s2,sizeof(s1));
	But this is very risky and can end up being a major bug in your code!. So try not to do this kind of memcmp() operations on structures variables as far as possible!
	193.	Can we pass constant values to functions which accept structure arguments?
	If you are trying to do something like this myfunction((struct mystruct){10,20});
	then, it wont work!. Use a temporary structure variable.
	194.	How does one use fread() and fwrite()? Can we read/write structures to/from files?
	Its easy to write a structure into a file using fwrite()
	 
	fwrite(&somestruct, sizeof somestruct, 1, fp);
	A similat fread() invocation can read it back in. But, data files so written will not be portable (specially if they contain floating point numbers). Also that if the structure has any pointers, only the pointer values will be written, and they are most unlikely to be valid when read back in. One must use the "rb/wb" flag when opening the files.
	A more portable solution is to write code to write and read a structure, field-by-field, in a portable (perhaps ASCII) way!. This is simpler to port and maintain.
	195.	Why do structures get padded? Why does sizeof() return a larger size?
	Padding enables the CPU to access the members faster. If they are not aligned (say to word boundaries), then accessing them might take up more time. So the padding results in faster access. This is also required to ensure that alignment properties are preserved when an array of contiguous structures is allocated. Even if the structure is not part of an array, the end padding remains, so that sizeof() can always return a consistent size.
	196.	Can we determine the offset of a field within a structure and directly access that element?
	The offsetof() macro(<stddef.h>) does exactly this. A probable implementation of the macro is
	#define offsetof(type, mem) ((size_t)((char *)&((type *)0)->mem - (char *)(type *)0))
	This can be used as follows. The offset of field a in struct mystruct is offset_of_a = offsetof(struct mystruct, a)
	If structpointer is a pointer to an instance of this structure, and field a is an int, its value can be set indirectly with
	*(int *)((char *)structpointer + offset_of_a) = some_value;