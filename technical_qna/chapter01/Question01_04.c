#include <stdlib.h>
#include <stdio.h>


// 	The right way of declaring a structure for a linked list in a C program is struct node
	{
	int value;
	struct node *next;
	};
	typedef struct node *mynode;

	Note that the following are not correct

	typedef struct
	{
	int value; mynode next;
	} *mynode;

// 	The typedef is not defined at the point where the "next" field is declared.

	struct node
	{
	int value;
	struct node next;
	};
	typedef struct node mynode;
// 	You can only have pointer to structures, not the structure itself as its recursive!