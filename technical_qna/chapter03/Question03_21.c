#include <stdlib.h>
#include <stdio.h>

// 	Here is how you do it
// 	max = ( ( a > b ) ? ( ( a > c ) ? a : c ) : ( ( b > c ) ? b : c ) ) ;
// 	Here is another way
// 	max = ( ( a > b ) ? a : b ) > c ? ( ( a > b ) ? a : b ) : c ; Here is some code to find the max of 4 numbers...
// 	Method1
	#include <stdio.h>
	#include <stdlib.h>
	#define max2( x , y )  ( ( x ) > ( y ) ? ( x ) : ( y ) )
	#define max4( a , b , c , d ) max2( max2( ( a ) , ( b ) ) , max2( ( c ) , ( d ) ) ) int main ( void )
	{
	 
	printf ( "Max: %d\n", max4(10,20,30,40));
	printf ( "Max: %d\n", max4(10,0,3,4)); return EXIT_SUCCESS;
	}

	Method2
	#include <stdio.h>
	#include <stdlib.h>
	int retMax( int i1, int i2 , int i3 , int i4 )
	{

	return( ( ( i1 > i2 ) ? i1 : i2 ) > ( ( i3 > i4 ) ? i3 : i4 ) ? ( ( i1 > i2 ) ? i1 : i2 ) : ( ( i3
	> i4 ) ? i3 : i4 ) ) ;
	}
	int main()
	{

	int val = 0 ;
	val = retMax(10, 200, 10, 530);
	val = retMax(9, 2, 5, 7);
	return 0;
	}