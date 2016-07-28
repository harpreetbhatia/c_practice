#include <stdlib.h>
#include <stdio.h>

	Another "Yeah, I am a jerk, kick me! kind of a question. I simply dont know why they ask these questions.
	Nevertheless, for the benefit of mankind...
	Method1 (Using recursion)
	void printUp(int startNumber, int endNumber)
	{

	if ( startNumber > endNumber ) return;
	printf("[%d]\n", startNumber++); printUp( startNumber , endNumber ) ;
	}

	Method2 (Using goto)
	void printUp(int startNumber, int endNumber)
	{

	 
	start:
	 


	if ( startNumber  >  endNumber )
	{
	 

	 


	}
	else
	{
	 
	goto end;






	printf("[%d]\n", startNumber++);
	 



	end:


	}
	 


	}


	return;
	 
	goto start;
	 