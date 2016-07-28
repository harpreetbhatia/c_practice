#include <stdlib.h>
#include <stdio.h>

// 	I have a really funny answer
// 	Declare variable names that are keywords in C++ but not C.
	#include <stdio.h> int main( void )
	{

	int old , new = 3 ; return 0;
	}

// 	This will compile in C, but not in C++! 64.How to swap the two nibbles in a byte ? Try this
	#include <stdio.h>
	unsigned char swap_nibbles(unsigned char c)
	{
	 
	unsigned char temp1, temp2; temp1 = c & 0x0F;
	temp2 = c & 0xF0; temp1 = temp1 << 4; temp2 = temp2 >> 4;
	return( temp2 | temp1 ) ; //adding the bits
	}

	int main(void)
	{

	char ch = 0x34 ;
	printf("\nThe exchanged value is %x",swap_nibbles(ch)); return 0;
	}