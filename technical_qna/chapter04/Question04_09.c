#include <stdlib.h>
#include <stdio.h>

	Here are the C program snippets to implement these traversals...
	Preorder
	preorder ( mynode *root )
	 
	{
	if ( root )
	{

	printf("Value : [%d]", root->value); preorder ( root -> left ) ;
	preorder ( root -> right ) ;
	}
	}

	Postorder
	postorder( mynode *root )
	{

	if ( root )
	{

	postorder ( root -> left ) ; postorder ( root -> right ) ;
	printf("Value : [%d]", root->value);
	}
	}

	Inorder
	inorder ( mynode *root )
	{

	if ( root )
	{

	inorder ( root -> left ) ; printf("Value : [%d]", root->value); inorder ( root -> right ) ;
	}
	 
	}
	Time complexity of traversals is O(n).