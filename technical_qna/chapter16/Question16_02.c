#include <stdlib.h>
#include <stdio.h>

	This is a trick question :
	There is a way to do this. Using structures. struct mystruct {
	int value; int length;
	char string[1];

	};
	Now, when allocating memory to the structure using malloc(), allocate more memory than what the structure would normally require!. This way, you can access beyond string [0] (till the extra amount of memory you have allocated, ofcourse).
	But remember, compilers which check for array bounds carefully might throw warnings. Also, you need to have a length field in the structure to keep a count of how big your one element array really is :).
	A cleaner way of doing this is to have a pointer instead of the one element array and allocate memory for it seperately after allocating memory for the structure.
	struct mystruct
	{

	int value;
	char *string; // Need to allocate memory using malloc() after allocating memory for the strucure.
	};