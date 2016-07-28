#include <stdlib.h>
#include <stdio.h>

// 	Use the following Macros
// 	    FILE 	Source file name (string constant) format "patx.c"
// 	    LINE 	Current source line number (integer)
// 	    DATE 	Date compiled (string constant)format "Dec 14 1985"
// 	    TIME 	Time compiled (string constant) format "15:24:26"
// 	    TIMESTAMP 	Compile date/time (string constant)format "Tue Nov 19 11:39:12 1997"
// 	Usage example
	 
	static char stamp[] =	"***\nmodule "    FILE 	 "\n***";
	...
	int main()
	{
	 
	"\ncompiled "    TIMESTAMP 	
	 

	...
	if ( (fp = fopen(fl,"r")) == NULL )
	{

	 



	}
	...
	}
	 
	printf( "open failed, line %d\n%s\n", LINE , stamp ); exit( 4 );
	 

// 	And the output is something like
// 	*** open failed, line 67
// 	******
// 	module myfile.c
// 	compiled Mon Jan 15 11:15:56 1999
// 	***