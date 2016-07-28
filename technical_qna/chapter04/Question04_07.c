#include <stdlib.h>
#include <stdio.h>

	This C code will create a new mirror copy tree.
	mynode *copy( mynode *root )
	{

	mynode  *temp; if( root == NULL)
	return ( NULL );
	temp = ( mynode * ) malloc( sizeof ( mynode ) ); temp -> value  =  root -> value ;
	temp -> left = copy( root -> right ); temp -> right = copy( root -> left ) ; return ( temp );
	}

	This code will will only print the mirror of the tree
	void tree_mirror(struct node* node)
	 
	{
	struct node *temp; if ( node == NULL )
	{

	 


	}
	else
	{











	}
	}
	 
	return;






	tree_mirror ( node -> left ); tree_mirror ( node -> right );
	// Swap the pointers in this node temp =  node -> left;
	node -> left = node -> right ; node -> right  =  temp ;