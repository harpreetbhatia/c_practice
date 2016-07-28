#include <stdlib.h>
#include <stdio.h>

// 	Here is some C code...
	int maxDepth( struct node* node )
	{

	if ( node == NULL )
	{
	 


	}
	else
	{
	 
	return ( 0 );






	int leftDepth  =  maxDepth ( node -> left ); int rightDepth = maxDepth ( node -> right ); if ( leftDepth  >  rightDepth )
	return ( leftDepth + 1 );
	 

	 
	else


	}
	}
	 


	return ( rightDepth + 1 );