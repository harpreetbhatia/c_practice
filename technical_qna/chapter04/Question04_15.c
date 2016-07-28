#include <stdlib.h>
#include <stdio.h>

// 	Here is a C program to do the same... 
	void count_leaf ( mynode *root )
	{

	if ( root != NULL )
	 
	{
	count_leaf ( root -> left ) ;
	if ( root -> left == NULL && root -> right == NULL )
	{

	// This is a leaf! count++;
	}

	count_leaf ( root -> right ) ;
	}
	}