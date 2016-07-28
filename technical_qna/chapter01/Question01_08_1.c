#include <stdlib.h>
#include <stdio.h>

// 	Method1
	 

	p = head; q = head;

	if( q -> next -> next != NULL)
	{
	p = p -> next;
	q = q -> next -> next;
	}
	printf("The middle element is %d",p->data);

// 	Here p moves one step, where as q moves two steps, when q reaches end, p will be at the middle of the linked list.