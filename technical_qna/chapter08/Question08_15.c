#include <stdlib.h>
#include <stdio.h>

	It wont if the prototpe is around. It will ideally scream out with an error like Too many arguments  or  Too few arguments
	But if the prototype is not around, the behavior is undefined. Try this out
	#include <stdio.h>
	/*
	int foo(int a);
	int foo2(int a, int b);
	*/
	int main(int a)
	{

	int (*fp)(int a); a = foo();
	a = foo2(1); exit(0);
	}
	int foo(int a)
	{

	return(a);
	}

	int foo2(int a, int b)
	{
	 
	return(a+b);
	}