#include <stdlib.h>
#include <stdio.h>

	// This is a very popular interview question, which most people go wrong. The ideal solution to this problem is to keep the linked list sorted as you build it. This really saves a lot of time which would have been required to sort it.

	// However....

	// Method1 (Usual method)

	// The general idea is to decide upon a sorting algorithm (say bubble sort). Then, one needs to come up with different scenarios to swap two nodes in the linked list when they are not in the required order. The different scenarios would be something like

	// 1.	When the nodes being compared are not adjacent and one of them is the first node.
	// 2.	When the nodes being compared are not adjacent and none of them is the first node
	// 3.	When the nodes being compared are adjacent and one of them is the first node.
	// 4.	When the nodes being compared are adjacent and none of them is the first node.

	// One example bubble sort for a linked list goes like this for(i = 1; i < n; i++)
	 
	{
	p1 = head;
	p2 = head->next; p3 = p2->next;

	for(j = 1; j <= (n - i); j++)
	{
	if(p2->value < p3->value)
	{
	 





	}
	else
	{



	}
	}
	}
	 
	p2->next = p3->next; p3->next = p2;
	p1->next = p3; p1	= p3;
	p3	= p2->next;



	p1 = p2; p2 = p3;
	p3 = p3->next;
	 

// 	As you can see, the code becomes quite messy because of the pointer logic. Thats why I have not elaborated too much on the code, nor on variations such as soring a doubly linked list. You have to do it yourself once to understand it.
