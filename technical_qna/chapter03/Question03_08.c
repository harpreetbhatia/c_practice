#include <stdlib.h>
#include <stdio.h>

	int pow( int x ,  int y )
	{

	if( y  == 1)
	return x ;
	return  x * pow ( x ,  y - 1 ) ;
	}

	Divide and Conquer C program
	#include <stdio.h>
	int main( int argc , char *argv[] )
	{

	printf("\n[%d]\n",pow(5,4));
	 
	}
	int pow(int x, int n)
	{

	if ( n == 0 )
	return ( 1 ) ; else if ( n % 2 == 0 )
	{

	 


	}
	else
	{


	}
	}
	 
	return ( pow ( x , n / 2 ) * pow ( x , ( n / 2 ) ) ) ;






	return ( x * pow ( x , n / 2 ) * pow ( x , ( n / 2 ) ) ) ;
	 

// 	Also, the code above can be optimized still by calculating pow(z, (n/2)) only one time (instead of twice) and using its value in the two return() expressions above.
