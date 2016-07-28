#include <stdlib.h>
#include <stdio.h>

	Here is a recursive C program
	 
	fact( int n )
	{

	int fact ;
	if ( n == 1 )
	return ( 1 ) ;

	else
	fact  =  n  *  fact ( n - 1 ) ;

	return ( fact ) ;
	}

	Please note that there is no error handling added to this function (to check if n is negative or 0. Or if n is too large for the system to handle). This is true for most of the answers in this website. Too much error handling and standard compliance results in a lot of clutter making it difficult to concentrate on the crux of the solution. You must ofcourse add as much error handling and comply to the standards of your compiler when you actually write the code to implement these algorithms.
