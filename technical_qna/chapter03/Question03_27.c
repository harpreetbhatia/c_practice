#include <stdlib.h>
#include <stdio.h>

// 	99% of the people who attend interviews can't answer this question, believe me!. Here is a recursive C program which does this....
	#include<stdio.h>
	void generatebits(int num); void generatebits(int num)
	{

	int temp; if ( num )
	{

	temp = num % 2; generatebits( num >>= 1 ) ; printf("%d",temp);
	}
	}

	int main()
	{

	int num;
	printf("\nEnter a number\n"); scanf("%d", &num);
	printf("\n\n"); generatebits(num); getch( );
	return(0);
	}

// 	The reason we have shown a recursive algorithm is that, because of the magic of recursion, we dont have to reverse the bits generated to produce the final output. One can always write an iterative algorithm to accomplish the same, but it would require you to
	 
// 	first store the bits as they are generated and then reverse them before producing the final output.
