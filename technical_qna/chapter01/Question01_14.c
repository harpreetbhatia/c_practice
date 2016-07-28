#include <stdlib.h>
#include <stdio.h>


// 	Here is a solution which is often called as the solution that uses frames.

// 	Suppose one needs to get to the 6th node from the end in this LL. First, just keep on
	 
// 	incrementing the first pointer (ptr1) till the number of increments cross n (which is 6 in this case)


// 	STEP 1 : 1(ptr1,ptr2) -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10

// 	STEP 2 : 1(ptr2) -> 2 -> 3 -> 4 -> 5 -> 6(ptr1) -> 7 -> 8 -> 9 -> 10

// 	Now, start the second pointer (ptr2) and keep on incrementing it till the first pointer (ptr1) reaches the end of the LL.

// 	STEP 3 : 1 -> 2 -> 3 -> 4(ptr2) -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 (ptr1)
// 	So here you have!, the 6th node from the end pointed to by ptr2! Here is some C code..
	struct node
	{
	int data;
	struct node *next;
	}mynode;

	mynode * nthNode(mynode *head, int n /*pass 0 for last node*/)
	{
	mynode *ptr1,*ptr2 ; int count ;

	if( !head )
	{
	return( NULL ) ;
	}

	ptr1 = head ; ptr2 = head ; count = 0 ;

	while( count < n )
	{
	count++ ;
	if ( ( ptr1 = ptr1 -> next ) == NULL )
	{
	//Length of the linked list less than n. Error. return( NULL );
	}
	}
	while( ( ptr1 = ptr1 -> next ) != NULL )
	{
	 
	ptr2 = ptr2 -> next ;
	}
	return( ptr2 );
	}
