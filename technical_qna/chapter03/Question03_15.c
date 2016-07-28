#include <stdlib.h>
#include <stdio.h>

	char *myfunction( int n )
	{

	char buffer[20]; sprintf(buffer, "%d", n); return retbuf;
	}

	This wont work either!
	char *myfunc1( )
	{

	char temp[] = "string"; return temp;
	}

	char *myfunc2( )
	{

	char temp[] = { 's', 't', 'r', 'i', 'n', 'g', '\0' }; return temp;
	 
	}
	int main( )
	{

	puts ( myfunc1( ) ) ;
	puts ( myfunc2( ) );
	}

	The returned pointer should be to a static buffer (like static char buffer[20];), or to a buffer passed in by the caller function, or to memory obtained using malloc(), but not to a local array.
	This will work
	char *myfunc( )
	{

	char *temp = "string"; return temp;
	}

	int main()
	{

	puts ( someFun ( ) ) ;
	}

	So will this calling_function ( )
	{

	char *string; return_string( &string ); printf(?\n[%s]\n?, string);
	}

	boolean return_string (char **mode_string  /* Pointer to a pointer! */ )
	{
	 
	*string = (char *) malloc ( 100 * sizeof ( char ) ) ;
	DISCARD strcpy ( (char *) *string , ( char * ) ? Something ? ) ;
	}
