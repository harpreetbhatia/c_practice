#include <stdlib.h>
#include <stdio.h>

// 	Here is a simple C program to accomplish the same.
	 
	int compare_linked_lists( struct node *q, struct node *r )
	{
	static int flag ;
	if ( ( q == NULL ) && ( r == NULL ) )
	{
	 

	}
	else
	{
	 
	flag=1;



	if ( q == NULL  ||  r == NULL )
	{
	 
	flag = 0 ;
	}
	if ( q -> data != r -> data )
	{
	 

	}
	else
	{

	}
	}
	 
	flag = 0;



	compare_linked_lists ( q -> link , r -> link ) ;
	 
	return ( flag ) ;
	}
// 	Another way is to do it on similar lines as strcmp() compares two strings, character by character (here each node is like a character).
