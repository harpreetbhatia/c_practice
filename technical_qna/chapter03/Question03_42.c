#include <stdlib.h>
#include <stdio.h>

	Suppose you have a big string
	This is a big string which I want to split at equal intervals, without caring about the words.
	 
	Now, to split this string say into smaller strings of 20 characters each, try this
	#define maxLineSize 20 split( char *string )
	{

	int i, length;
	char dest[maxLineSize + 1]; i = 0;
	length = strlen(string);
	while( ( i + maxLineSize )  <=  length )
	{

	strncpy( dest , ( string + i ) , maxLineSize ) ; dest[maxLineSize - 1]  =  '\0' ;
	i = i + strlen( dest ) - 1 ; printf("\nChunk : [%s]\n", dest);
	}

	strcpy( dest , ( string + i ) ) ; printf("\nChunk : [%s]\n", dest);
	}