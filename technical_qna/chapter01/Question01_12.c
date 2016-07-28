#include <stdlib.h>
#include <stdio.h>

// 	Before looking at the answer, try writing a simple C program (with a for loop) to do this.
	 
// 	Quite a few people get this wrong.

// 	This is the wrong way to do it:

	struct list *listptr, *nextptr ;
	for( listptr = head ; listptr != NULL ; listptr = listptr -> next )
	{
	free( listptr ) ;
	}
	
// 	If you are thinking why the above piece of code is wrong, note that once you free
// 	the listptr node, you cannot do something like listptr = listptr->next!. Since listptr is already freed, using it to get listptr->next is illegal and can cause unpredictable results
// 	This is the right way to do it:

	struct list *listptr, *nextptr;
	for( listptr = head ; listptr != NULL ; listptr = nextptr )
	{
	nextptr = listptr -> next ; free( listptr ) ;
	}