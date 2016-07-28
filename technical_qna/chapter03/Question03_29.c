#include <stdlib.h>
#include <stdio.h>

	typedef struct node
	{

	float cf;
	float px; float py;
	struct node *next;
	}mynode;
	float evaluate(mynode *head)
	{

	float x,y,sum; sum = 0; mynode *poly;
	for( poly =  head -> next ; poly != head ; poly =  poly -> next  )
	{

	sum = sum + poly -> cf * pow( x , poly -> px ) * pow( y, poly -> py )   ;
	}

	return( sum ) ;
	}