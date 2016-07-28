#include <stdlib.h>
#include <stdio.h>

// 	Here is some sample C code. The idea is to keep on moving till you hit the left most node in the tree

	int minValue(struct node* node)
	{

	struct node *current = node ; while ( current -> left != NULL )
	{

	current  =  current -> left ;
	}

	return( current -> data );
	}

// 	On similar lines, to find the maximum value, keep on moving till you hit the right most node of the tree.