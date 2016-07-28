#include <stdlib.h>
#include <stdio.h>

	Here is an example C program to solve the Tower Of Hanoi problem... main()
	{

	towers_of_hanio( n , 'L' , 'R' , 'C' ) ;
	}

	towers_of_hanio ( int n , char from , char to , char temp )
	 
	{
	if ( n > 0 )
	{

	tower_of_hanio ( n-1, from , temp , to ) ; printf("\nMove disk %d from %c to %c\n", n, from, to); tower_of_hanio ( n-1, temp , to , from ) ;
	}
	}
