#include <stdlib.h>
#include <stdio.h>

	This is one of the very popular interview questions, so take a good look at it!. myfunction( int *ptr )
	{

	 



	}
	main( )
	{
	 
	int myvar = 100; ptr = &myvar;
	 
	int *myptr ; myfunction ( myptr ) ;
	//Use pointer myptr.
	}
	Do you think this works? It does not!.
	Arguments in C are passed by value. The called function changed the passed copy of the pointer, and not the actual pointer.
	There are two ways around this problem
	Method1
	Pass in the address of the pointer to the function (the function needs to accept a pointer- to-a-pointer).
	calling_function()
	{

	char *string;
	return_string(/* Pass the address of the pointer */&string); printf(?\n[%s]\n?, string);
	}

	boolean return_string( char **mode_string  /*Pointer to a pointer! */ )
	{

	*string = (char * ) malloc(100 * sizeof( char ) ) ; // Allocate memory to the pointer passed, not its copy.
	DISCARD strcpy( (char * ) *string , ( char * ) ? Something ? ) ;

	}
	Method2
	Make the function return the pointer. char *myfunc( )
	{

	char *temp = "string"; return temp;
	 
	}
	int main()
	{
	puts( myfunc( ) );
	}