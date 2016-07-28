#include <stdlib.h>
#include <stdio.h>

	Check out this simple implementation
	mynode *long_add(mynode *h1, mynode *h2, mynode *h3)
	{

	mynode *c, *c1, *c2; int sum, carry, digit; carry = 0;
	c1 = h1->next; c2 = h2->next;
	while(c1 != h1 && c2 != h2)
	{

	sum = c1 -> value + c2 -> value + carry ; digit  =  sum  %  10 ;
	carry  =  sum  / 10 ;
	 
	h3 = insertNode( digit , h3 ); c1  =  c1 -> next ;
	c2  =  c2 -> next ;
	}

	if ( c1 != h1 )
	{

	 



	}
	else
	{




	}
	 
	c = c1; h = h1;





	c = c2; h = h2;
	 

	while ( c != h )
	{

	sum = c -> value + carry ; digit  =  sum  %  10 ;
	carry  =  sum  / 10 ;
	h3 = insertNode( digit , h3 ); c  =  c -> next ;
	}

	if ( carry == 1 )
	{

	h3  =  insertNode( carry ,  h3 ) ;
	}

	return( h3 ) ;
	 
	}