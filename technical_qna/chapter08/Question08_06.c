#include <stdlib.h>
#include <stdio.h>


	 
	Before reading the answer, please be aware that inline functions are non-standard C. They are provided as compiler extensions. But, nevertheless, one should know what they are used for.
	The inline comment is a request to the compiler to copy the code into the object at every place the function is called. That is, the function is expanded at each point of call. Most of the advantage of inline functions comes from avoiding the overhead of calling an actual function. Such overhead includes saving registers, setting up stack frames, and so on. But with large functions the overhead becomes less important. Inlining tends to blow up the size of code, because the function is expanded at each point of call.
	int myfunc(int a)
	{

	...
	}

	inline int myfunc(int a)
	{

	...
	}

	Inlined functions are not the fastest, but they are the kind of better than macros (which people use normally to write small functions).
	#define myfunc(a)  \
	{ \

	...	\
	}

	The problem with macros is that the code is literally copied into the location it was called from. So if the user passes a "double" instead of an "int" then problems could occur.
	However, if this senerio happens with an inline function the compiler will complain about incompatible types. This will save you debugging time stage.
	Good time to use inline functions is
	1.	There is a time criticle function.
	2.	That is called often.
	3.	Its small. Remember that inline functions take more space than normal functions.
	Some typical reasons why inlining is sometimes not done are:
	 
	1.	The function calls itself, that is, is recursive.
	2.	The function contains loops such as for(;;) or while().
	3.	The function size is too large.