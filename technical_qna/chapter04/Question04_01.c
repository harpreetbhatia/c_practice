#include <stdlib.h>
#include <stdio.h>

// 	Here is some C code to get the height of the three 
    tree_height( mynode *p )
	{

	if ( p == NULL )
	return( 0 ); if( p -> left )
	{

	h1=tree_height( p -> left ) ;
	}

	if ( p => right )
	{

	h2=tree_height( p -> right ) ;
	}

	return ( max ( h1 , h2 ) + 1 );
	}
	 
// 	The degree of the leaf is zero. The degree of a tree is the max of its element degrees. A binary tree of height n, h > 0, has at least h and at most (2^h -1) elements in it. The height of a binary tree that contains n, n>0, elements is at most n and atleast log(n+1) to the base 2.
// 	Log(n+1) to the base 2 = h n = (2^h - 1)