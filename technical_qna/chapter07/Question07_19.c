#include <stdlib.h>
#include <stdio.h>

	sizeof() is a compile time operator. To calculate the size of an object, we need the type information. This type information is available only at compile time. At the end of the compilation phase, the resulting object code doesn't have (or not required to have) the type information. Of course, type information can be stored to access it at run-time, but this results in bigger object code and less performance. And most of the time, we don't need it. All the runtime environments that support run time type identification (RTTI) will retain type information even after compilation phase. But, if something can be done in compilation time itself, why do it at run time?
	On a side note, something like this is illegal...
	 
	printf("%u\n", sizeof(main));
	This asks for the size of the main function, which is actually illegal:

	The sizeof operator shall not be applied to an expression that has function type....
