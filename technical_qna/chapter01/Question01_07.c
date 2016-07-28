#include <stdlib.h>
#include <stdio.h>


// 	This is also one of the classic interview questions
// 	There are multiple answers to this problem. Here are a few C programs to attack this problem.
// 	Brute force method
// 	Have a double loop, where you check the node pointed to by the outer loop, with every node of the inner loop.

	typedef struct node
	{
	void *data;
	struct node *next;
	}mynode;

	mynode * find_loop( NODE * head )
	{
	mynode *current  = head;
	while( current -> next  !=  NULL )
	{
	mynode *temp  = head;
	while( temp -> next  !=  NULL && temp  !=  current  )
	 
	{
	if( current -> next  ==  temp )
	{
	printf("\nFound a loop."); return current;
	}
	temp  =  temp -> next;
	}
	current  =  current -> next;
	}
	return NULL;
	}

// 	Visited flag

// 	Have a visited flag in each node of the linked list. Flag it as visited when you reach the node. When you reach a node and the flag is already flagged as visited, then you know there is a loop in the linked list.

// 	Fastest method
// 	Have 2 pointers to start of the linked list. Increment one pointer by 1 node and the other by 2 nodes. If there's a loop, the 2nd pointer will meet the 1st pointer somewhere. If it does, then you know there's one.
// 	Here is some code

	p = head;
	q = head -> next;
	while( p != NULL && q != NULL )
	{
	if( p == q )
	{
	//Loop detected! 
	exit( 0 );
	}
	p = p -> next;
	q = ( q -> next ) ? ( q -> next -> next ) : q -> next;
	}
	// No loop.