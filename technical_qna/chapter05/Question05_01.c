#include <stdlib.h>
#include <stdio.h>

	This is one of the most frequently asked interview questions of all times...
	There are a number of ways to count the number of bits set in an integer. Here are some C programs to do the same.
	Method1
	This is the most basic way of doing it.
	#include<stdio.h> int main()
	{

	unsinged int num=10; int ctr=0; for(;num!=0;num>>=1)
	{

	if(num&1)
	{

	ctr++;
	}
	}

	printf("\n Number of bits set in [%d] = [%d]\n", num, ctr); return(0);
	}

	Method2
	This is a faster way of doing the same thing. Here the control goes into the while loop only as many times as the number of bits set to 1 in the integer!.
	 
	#include<stdio.h> int main()
	{

	int num=10; int ctr=0; while(num)
	{

	ctr++;
	num = num & (num - 1); // This clears the least significant bit set.
	}

	printf("\n Number of bits set in [%d] = [%d]\n", num, ctr); return(0);
	}

	Method3
	This method is very popular because it uses a lookup table. This speeds up the computation. What it does is it keeps a table which hardcodes the number of bits set in each integer from 0 to 256.
	For example
	0 - 0 Bit(s) set.
	1	- 1 Bit(s) set.
	2	- 1 Bit(s) set.
	3	- 2 Bit(s) set.
	...
	So here is the code...
	const unsigned char LookupTable[]	= {  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	 





















	unsigned int num;
	unsigned int ctr;   // Number of bits set.
	 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
	4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8	};
	 

	ctr = LookupTable[num & 0xff] + LookupTable[(num >> 8) & 0xff] + LookupTable [(num >> 16) & 0xff] +
	LoopupTable[num >> 24];