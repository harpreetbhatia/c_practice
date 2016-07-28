#include <stdlib.h>
#include <stdio.h>

	No
	The only things that case be used inside a switch statement are constants or enums.
	Anything else will give you a constant expression required
	 
	error. That is something like this is not valid switch(i)
	{

	 
	case 1:




	case j:




	}
	 


	// Something; break;

	// Something; break;
	 

	So is this. You cannot switch() on strings switch(i)
	{

	case "string1" :
	// Something; break;
	case "string2" :
	// Something; break;
	}

	This is valid, however switch( i )
	{

	 
	case 1:
	 


	// Something; break;
	 
	case 1*2+4:
	 
	// Something; break;
	}

	This is also valid, where t is an enum switch( i )
	{

	 
	case 1:




	case t:




	}
	 


	// Something; break;

	// Something; break;
	 

	Also note that the default case does not require a break; if and only if its at the end of the switch() statement. Otherwise, even the default case requires a break;