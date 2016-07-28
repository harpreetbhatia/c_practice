#include <stdlib.h>
#include <stdio.h>

// 	Here is a C program which does that... 
	mynode *copy ( mynode *root )
	{

	mynode *temp;
	if ( root == NULL )
	return ( NULL ) ;
	temp = ( mynode * ) malloc ( sizeof ( mynode ) ) ; temp -> value  =  root -> value ;
	temp -> left = copy ( root -> left ) ; temp -> right = copy ( root -> right ) ; return ( temp ) ;
	}