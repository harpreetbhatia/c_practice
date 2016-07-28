#include <stdlib.h>
#include <stdio.h>

// 	Use something like
	( int ) ( num  <  0  ?  ( num  -  0.5 )  :  ( num  +  0.5 ) )


	74.	How can we sum the digits of a given number in single statement?
	Try something like this
	# include<stdio.h> void main()
	{

	int num=123456; int sum=0;
	for( ; num > 0 ; sum += num % 10 , num /= 10 ) ; // This is the "single line". printf("\nsum = [%d]\n", sum);
	}

	If there is a simpler way to do this, let me know!
