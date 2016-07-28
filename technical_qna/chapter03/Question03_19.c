#include <stdlib.h>
#include <stdio.h>

	int gcd(int a, int b)
	{

	int temp; while(b)
	{

	temp = a % b ;  a  =  b ;
	b = temp;
	}

	return(a);
	}

	// Recursive algorithm
	int gcd_recurse( int a , int b )
	{

	int temp;
	temp = a % b ; if (temp == 0)
	{

	 


	}
	else
	{
	 
	return ( b ) ;






	return ( gcd_recurse ( b, temp ) ) ;
	 
	}
	}

	And here is the output ... Iterative
	---------------- GCD( 6, 4) = [2]
	GCD( 4, 6) = [2]
	GCD( 3,17) = [1]
	GCD(17, 3) = [1]
	GCD( 1, 6) = [1]
	GCD(10, 1) = [1]
	GCD(10, 6) = [2]
