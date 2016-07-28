#include <stdlib.h>
#include <stdio.h>

	Here are a few C programs....
	mynode *search ( int value , mynode *root )
	{
	 
	while ( root != NULL && value != root -> value )
	{

	root  =  ( value <  root -> value ) ? root -> left : root -> right ;
	}

	return ( root ) ;
	}

	Here is another way to do the same
	mynode *recursive_search ( int item , mynode *root )
	{

	if ( root == NULL  || item == root -> value )
	{

	return ( root ) ;
	}

	if ( item < root -> info )
	{

	 


	}
	else
	{


	}
	}
	 
	return ( recursive_search ( item , root -> left ) ) ;






	return ( recursive_search ( item , root -> right ) ) ;
	 
