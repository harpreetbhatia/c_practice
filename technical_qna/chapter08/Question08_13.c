#include <stdlib.h>
#include <stdio.h>

	Good question
	Something like this wont work
	#include <stdarg.h> main()
	{

	display("Hello", 4, 12, 13, 14, 44);
	}

	display(char *s,...)
	{

	show(s,...);
	}

	show(char *t,...)
	{

	va_list ptr; int a;
	 
	va_start(ptr,t);
	a = va_arg(ptr, int); printf("%f", a);
	}

	This is the right way of doing it
	#include <stdarg.h> main()
	{

	display("Hello", 4, 12, 13, 14, 44);
	}

	display(char *s,...)
	{

	va_list ptr; va_start(ptr, s); show(s,ptr);
	}

	show(char *t, va_list ptr1)
	{

	int a, n, i; a=va_arg(ptr1, int); for(i=0; i<a; i++)
	{

	n=va_arg(ptr1, int); printf("\n%d", n);
	}
	}
