#include <stdlib.h>
#include <stdio.h>



	// Method2 (Divide and Conquer using merge sort)
	// The pseudocode for this method is 
	typedef struct node
	{
	int value;
	struct node *next;
	}mynode;

	mynode *head, *tail; int size;

	mynode *mergesort(mynode *list, int size); void display(mynode *list);

	mynode *mergesort(mynode *list, int size)
	{
	int size1, size2;
	 
	mynode *tempnode1, *tempnode2, *tempnode3;

	if( size<=2 )
	{
	if(size==1)
	{
	 


	}
	else
	{
	 
	// Nothing to sort! return(list);



	if(list->value < list->next->value
	{
	 





















	}
	}
	else
	{
	 


	}
	else
	{















	}
	 
	// These 2 nodes are already in right order, no need to sort return(list);



	// Need to swap these 2 nodes
	/* Here we have 2 nodes
	*
	*node 1 -> node2 -> NULL
	*
	*	This should be converted to
	*
	*	node2 -> node1 -> NULL
	*
	*/
	tempnode1 = list; tempnode2 = list->next;
	tempnode2->next = tempnode1; tempnode1->next = NULL; return(tempnode2);
	 
	// The size of the linked list is more than 2.
	// Need to split this linked list, sort the
	// left and right sub-linked lists and merge.
	// Split.
	// tempnode1 will have the first half of the linked list of size "size1".
	// tempnode2 will have the second half of the linked list of size "size2".

	// <CODE TO SPLIT THE LINKED LIST INTO TWO>
	// Sort the two halves recursively
	 
	tempnode1 = mergesort(tempnode1, size1); tempnode2 = mergesort(tempnode2, size2);

	// Now merge the sorted lists back, let tempnode3 point to that new list.

	// <CODE TO MERGE THE 2 LINKED LISTS BACK INTO A SINGLE SORTED LINKED LIST>

	return(tempnode3);
	}
	}

	// The code to merge the two already sorted sub-linked lists into a sorted linked list could be something like this..

	mynode * merge(mynode *a, mynode *b)
	{
	mynode *i, *j, *k, *c;

	i  = a;
	j  = b;
	c = getNewNode(); k = getNewNode();

	while(i != NULL && j != NULL)
	{
	if( i -> value < j -> value )
	{
	 


	}
	else
	{


	}
	}
	 
	k -> next = i; i = i -> next;



	k -> next = j; j = j -> next;
	 

	if( i != NULL)
	k -> next = i ;
	else
	k -> next = j;

	return( c -> next );

	}
	 