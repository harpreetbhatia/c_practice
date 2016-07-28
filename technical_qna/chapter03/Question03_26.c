#include <stdlib.h>
#include <stdio.h>

	An example of a palidrome is "avon sees nova"
	There a number of ways in which we can find out if a string is a palidrome or not. Here are a few sample C programs...
	Method1
	#include <stdio.h>
	 
	#include <string.h>
	#include <stdlib.h>
	#include <ctype.h>
	void isPalindrome(char *string); int main()
	{

	isPalindrome("avon sees nova"); isPalindrome("a"); isPalindrome("avon sies nova"); isPalindrome("aa"); isPalindrome("abc"); isPalindrome("aba"); isPalindrome("3a2");
	exit(0);
	}

	void isPalindrome( char *string )
	{

	char *start , *end ; if( string )
	{

	start = string;
	end   = string + strlen(string) - 1;
	while( ( *start == *end ) && ( start != end ) )
	{

	if ( start < end )
	start++; if ( end > start )
	 
	end--;
	}

	if( *start != *end )
	{

	 


	}
	else
	{


	}
	}
	 
	printf("\n[%s] - This is not a palidrome!\n", string);






	printf("\n[%s] - This is a palidrome!\n", string);
	 

	printf("\n\n");
	}

	Method2
	boolean palindrome( char string[] )
	{

	int count, countback, end, N; N   = strlen ( string ) ;
	end = N-1 ;
	for( ( count = 0, count <= end ) ; count <= ( end / 2 ) ; ++count ,--countback )
	{

	if ( string[count] != string[countback] )
	{

	return( FALSE );
	}
	}

	return(TRUE);
	 
	}