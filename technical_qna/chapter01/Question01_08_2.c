#include <stdlib.h>
#include <stdio.h>

	// Method2

	struct node *middle(struct node *head)
	{
	struct node *middle=NULL; int i;
	for( i = 1 ; head ; head = head -> next , i++)
	{
	if( i == 1 )
	middle = head ; else if ( ( i % 2 ) == 1 )
	middle = middle -> next ;
	}
	return middle;
	}
	
	// In a similar way, we can find the 1/3 th node of linked list by changing ( i % 2 == 1 ) to ( i
	// % 3 == 1 ) and in the same way we can find nth node of list by changing ( i % 2 == 1 ) to ( i % n == 1 ) but make sure ur ( n <= i ).
