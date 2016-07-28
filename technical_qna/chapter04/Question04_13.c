#include <stdlib.h>
#include <stdio.h>

	The node to be deleted might be in the following states
	*	The node does not exist in the tree - In this case you have nothing to delete.
	*	The node to be deleted has no children - The memory occupied by this node must be freed and either the left link or the right link of the parent of this node must be set to NULL.
	*	The node to be deleted has exactly one child - We have to adjust the pointer of the parent of the node to be deleted such that after deletion it points to the child of the node
	 
	being deleted.
	*	The node to be deleted has two children - We need to find the inorder successor of the node to be deleted. The data of the inorder successor must be copied into the node to be deleted and a pointer should be setup to the inorder successor. This inorder successor would have one or zero children. This node should be deleted using the same procedure as for deleting a one child or a zero child node. Thus the whole logic of deleting a node with two children is to locate the inorder successor, copy its data and reduce the problem to a simple deletion of a node with one or zero children.
	Here is some C code for these two situations
	Situation 1
	100  (parent) 50 (cur == psuc)
	20	80 (suc)
	90
	85  95
	Situation 2
	100 (parent)
	50 (cur)
	20	90
	80
	70 (suc)
	75
	72   76
	node *delete(int item, mynode *head)
	{

	mynode *cur, *parent, *suc, *psuc, q; if ( head -> lef t== NULL )
	{

	printf("\nEmpty tree!\n"); return ( head );
	 
	}
	parent  =  head ;
	cur	=  head -> left ;
	while ( cur != NULL && item != cur -> value  )
	{

	parent  = cur;
	cur   =  ( item < cur -> next )  ?  cur -> left : cur -> right ;
	}

	if ( cur == NULL )
	{

	printf("\nItem to be deleted not found!\n"); return ( head ) ;
	}

	// Item found, now delete it if ( cur -> left == NULL )
	q  =  cur -> right ;
	else if ( cur -> right == NULL ) q = cur -> left ;
	 
	else
	{
	 



	// Obtain the inorder successor and its parent psuc  =  cur ;
	cur  = cur -> left ;
	while ( suc -> left != NULL )
	{
	 

	psuc  =  suc ; suc  = suc->left ;
	 
	}
	if ( cur == psuc )
	{

	 



	}
	else
	{







	}
	 
	// Situation 1
	suc->left = cur->right ;






	// Situation 2
	suc -> left = cur -> left ; psuc -> left = suc -> right ; suc -> right  =  cur -> right ;
	 

	q  =  suc ;
	}

	// Attach q to the parent node if ( parent -> left == cur )
	parent -> left = q ;

	else
	parent -> rlink = q ;

	freeNode( cur ); return( head );
	}