#include <stdlib.h>
#include <stdio.h>


	Here are some C programs which implement the strcpy() function. This is one of the most frequently asked C interview questions.

	Method1
	 
	char *mystrcpy( char *dst, const char *src )
	{
	char *ptr; ptr = dst;
	while( *dst++ = *src++ ) ; return ( ptr );
	}

	The strcpy function copies src, including the terminating null character, to the location specified by dst. No overflow checking is performed when strings are copied or appended. The behavior of strcpy is undefined if the source and destination strings overlap. It returns the destination string. No return value is reserved to indicate an error.

	Note that the prototype of strcpy as per the C standards is char *strcpy(char *dst, const char *src);
	Notice the const for the source, which signifies that the function must not change the source string in anyway!.

	Method2

	char *my_strcpy(char dest[], const char source[])
	{
	int i = 0;
	while (source[i] != '\0')
	{
	dest[i] = source[i]; i++;
	}
	dest[i] = '\0'; return(dest);
	}

	Simple, isn't it?