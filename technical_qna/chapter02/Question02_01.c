#include <stdlib.h>
#include <stdio.h>

// 	The prototype of the atoi() function is ... int atoi(const char *string);
// 	Here is a C program which explains a different way of coding the atoi() function in the C language.

	#include<stdioi.h>

	int myatoi( const char *string );

	int main( int argc, char* argv[] )
	{
	printf("\n%d\n", myatoi("1998")); getch();
	return(0);
	}

	int myatoi( const char *string )
	{
	int i; i = 0;
	while( *string )
	{
	i = ( i << 3 ) + ( i << 1 ) + ( *string - '0' ); string++;
	// Dont increment i!
	 
	}
	return( i );
	}

// 	Try working it out with a small string like "1998", you will find out it does work!. Ofcourse, there is also the trivial method ....

// 	"1998" == 8 + (10 * 9) + (100 * 9) + (1 * 1000) = 1998
// 	This can be done either by going from right to left or left to right in the string
// 	One solution is given below

	int myatoi(const char* string)
	{
	int value = 0; if ( string )
	{
	while ( *string  && ( *string  <=  '9' &&  *string  >= '0' ) )
	{
	value = ( value * 10 ) + ( *string - '0' ) ; string++;
	}
	}
	return value;
	}

// 	Note that these functions have no error handling incorporated in them (what happens if someone passes non-numeric data (say "1A998"), or negative numeric strings (say
// 	"-1998")). I leave it up to you to add these cases. The essense is to understand the core logic first.