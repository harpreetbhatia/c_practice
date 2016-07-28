#include <stdlib.h>
#include <stdio.h>

// 	Check out this C program which creates an exact copy of a linked list. copy_linked_lists ( struct node *q , struct node **s )
	{
	if ( q != NULL )
	{
	*s = malloc ( sizeof ( struct node ) ) ; ( *s ) -> data = q -> data ;
	( *s ) ->  link = NULL ;
	copy_linked_list ( q -> link ,  & ( ( *s ) -> link ) );
	}
	}