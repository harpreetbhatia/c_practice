#include <stdlib.h>
#include <stdio.h>

// 	Here is a C program using recursion
	int identical( struct node* a , struct node* b )
	{

	if ( a == NULL  &&  b == NULL )
	{

	return ( true );
	 
	}
	else if ( a != NULL && b != NULL )
	{

	return( a -> data == b -> data && identical( a -> left , b -> left ) && identical( a -> right, b -> right ) );
	}
	else return(false);

	}