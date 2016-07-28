#include <stdlib.h>
#include <stdio.h>

	An assertion is a macro, defined in <assert.h>, for testing assumptions. An assertion is an
	 
	assumption made by the programmer. If its violated, it would be caught by this macro.
	For example int i,j;
	for(i=0;i<=10;i++)
	{

	j += 5;
	assert(i<5);
	}

	Runtime error: Abnormal program termination. assert failed (i<5), <file name>,<line number>
	If anytime during the execution, i gets a value of 0, then the program would break into the assertion since the assumption that the programmer made was wrong.
