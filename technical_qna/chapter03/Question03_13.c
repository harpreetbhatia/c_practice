#include <stdlib.h>
#include <stdio.h>

	First of all, Do you know what Little-Endian and Big-Endian mean?
	Little Endian means that the lower order byte of the number is stored in memory at the lowest address, and the higher order byte is stored at the highest address. That is, the little end comes first.
	For example, a 4 byte, 32-bit integer
	Byte3 Byte2 Byte1 Byte0 will be arranged in memory as follows: Base_Address+0  Byte0
	Base_Address+1 Byte1 Base_Address+2 Byte2 Base_Address+3  Byte3
	Intel processors use "Little Endian" byte order.
	"Big Endian" means that the higher order byte of the number is stored in memory at the lowest address, and the lower order byte at the highest address. The big end comes first.
	Base_Address+0 Byte3 Base_Address+1 Byte2 Base_Address+2 Byte1 Base_Address+3  Byte0
	Motorola, Solaris processors use "Big Endian" byte order.
	In "Little Endian" form, code which picks up a 1, 2, 4, or longer byte number proceed in the same way for all formats. They first pick up the lowest order byte at offset 0 and proceed from there. Also, because of the 1:1 relationship between address offset and byte number (offset 0 is byte 0), multiple precision mathematic routines are easy to code. In "Big Endian" form, since the high-order byte comes first, the code can test whether the number is positive or negative by looking at the byte at offset zero. Its not required to know how long the number is, nor does the code have to skip over any bytes to find the byte containing the sign information. The numbers are also stored in the order in which they are printed out, so binary to decimal routines are particularly efficient.
	 
	Here is some code to determine what is the type of your machine int num = 1;
	if ( * ( char * ) &num  ==  1 )
	{

	 


	}
	else
	{


	}
	 
	printf("\nLittle-Endian\n");






	printf("Big-Endian\n");
	 

	And here is some code to convert from one Endian to another. int myreversefunc( int num )
	{

	int byte0, byte1, byte2, byte3;
	byte0 = ( num & x000000FF ) >> 0 ; byte1 = ( num & x0000FF00 ) >> 8 ; byte2 = ( num & x00FF0000 ) >> 16 ; byte3 = ( num & xFF000000 ) >> 24 ;
	return ( ( byte0 << 24 ) | ( byte1 << 16 ) | ( byte2 << 8 ) | ( byte3 << 0 ) ) ;
	}

