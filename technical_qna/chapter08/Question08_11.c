#include <stdlib.h>
#include <stdio.h>

// 	Keep a table of names and their function pointers:
	 
	int myfunc1(), myfunc2(); struct
	{

	char *name;
	int (*func_ptr)();
	} func_table[] = {"myfunc1", myfunc1,"myfunc2", myfunc2,};
// 	Search the table for the name, and call via the associated function pointer.