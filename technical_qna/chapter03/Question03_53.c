#include <stdlib.h>
#include <stdio.h>

// 	Here is one version...
	#include <stdio.h> char *trim( char *s ) ;
	int main( int argc , char *argv[] )
	{

	char str1[] = " Hello I am Good " ; printf("\n\nBefore trimming : [%s]", str1); printf("\n\nAfter trimming : [%s]", trim(str1)); getch( ) ;
	}

	// The trim() function... char *trim( char *s )
	{

	char *p, *ps;
	for ( ps  =  p  =  s ;  *s  !=  '\0' ; s++ )
	{

	if ( !isspace( *s ) )
	{

	*p++  =  *s ;
	}
	}
	 
	*p = '\0' ; return( ps ) ;
	}

// 	And here is the output...
// 	Before trimming : [ Hello I am Good ] After trimming  : [HelloIamGood]