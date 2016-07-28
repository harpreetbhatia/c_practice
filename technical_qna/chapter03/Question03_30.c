#include <stdlib.h>
#include <stdio.h>

// 	Here is some pseudocode
	mynode *polynomial_add(mynode *h1, mynode *h2, mynode *h3)
	{

	mynode *p1, *p2;
	int x1, x2, y1, y2, cf1, cf2, cf; p1 = h1->next;
	 
	while(p1!=h1)
	{

	x1 = p1->px; y1 = p1->py; cf1 = p1->cf;
	// Search for this term in the second polynomial p2 = h2->next;
	while(p2 != h2)
	{

	x2 = p2->px; y2 = p2->py; cf2 = p2->cf;
	if(x1 == x2 && y1 == y2) break;
	p2 = p2->next;
	}

	if(p2 != h2)
	{

	 







	}
	else
	{


	}
	 
	// We found something in the second polynomial. cf = cf1 + cf2;
	p2->flag = 1;
	if( cf != 0 ){ h3 = addNode( cf , x1 , y1 , h3 ) ; }






	h3=addNode(cf,x1,y1,h3);
	 
	p1 = p1->next;
	}//while
	// Add the remaining elements of the second polynomail to the result while(p2 != h2)
	{

	if(p2->flag==0)
	{

	h3=addNode(p2->cf, p2->px, p2->py, h3);
	}

	p2=p2->next;
	}

	return(h3);
	}