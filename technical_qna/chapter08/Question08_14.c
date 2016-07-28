#include <stdlib.h>
#include <stdio.h>

	 
	Glad that you thought about doing something like this! Here is some code
	#include <stdarg.h> main()
	{

	int (*p1)();
	int (*p2)();
	int fun1(), fun2(); p1 = fun1;
	p2 = fun2; display("Bye", p1, p2);
	}

	display(char *s,...)
	{

	 














	}
	fun1()
	{


	}
	 
	int (*pp1)(), (*pp2)(); va_list ptr;
	typedef int (*f)(); //This typedef is very important. va_start(ptr,s);
	pp1 = va_arg(ptr, f); // va_arg(ptr, int (*)()); would NOT have worked! pp2 = va_arg(ptr, f);
	(*pp1)();
	(*pp2)();






	printf("\nHello!\n");
	 
	fun2()
	{


	}
	 



	printf("\nHi!\n");
	 