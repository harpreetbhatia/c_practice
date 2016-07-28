#include <stdlib.h>
#include <stdio.h>


	This is again one of the most frequently asked interview questions. Here is a C program which implements a basic version of printf(). This is a really, really simplified version of printf(). Note carefully how floating point and other compilcated support has been left out. Also, note how we use low level puts() and putchar(). Dont make a fool of yourself by using printf() within the implementation of printf()!

	#include<stdio.h>
	#include<stdarg.h>

	 
	main()
	{





	}
	 


	void myprintf(char *,...);
	char * convert(unsigned int, int); int i=65;
	char str[]="This is my string"; myprintf("\nMessage = %s%d%x",str,i,i);
	 

	void myprintf(char * frmt,...)
	{
	char *p;
	 
	int i; unsigned u; char *s; va_list argp;
	va_start(argp, fmt); p=fmt;
	for(p=fmt; *p!='\0';p++)
	{
	if(*p=='%')
	{
	 


	} p++;
	 
	putchar(*p); continue;
	 
	switch(*p)
	{
	 
	case 'c' :





	case 'd' :
	 

	i=va_arg(argp,int); putchar(i);
	break;

	i=va_arg(argp,int); if(i<0)
	{
	 

	i=-i; putchar('-');
	}

	 



	case 'o':





	case 's':
	 
	puts(convert(i,10)); break;

	i=va_arg(argp,unsigned int); puts(convert(i,8));
	break; s=va_arg(argp,char *);
	 




















	}

	va_end(argp);
	}
	 



	case 'u':





	case 'x':





	case '%':



	}
	 
	puts(s); break;

	u=va_arg(argp,argp, unsigned int); puts(convert(u,10));
	break;

	u=va_arg(argp,argp, unsigned int); puts(convert(u,16));
	break;

	putchar('%'); break;
	 


	char *convert(unsigned int, int)
	{
	static char buf[33]; char *ptr;

	ptr = &buf[ sizeof ( buff ) - 1 ];
	*ptr = '\0' ; do
	{
	*--ptr = "0123456789abcdef"[ num % base ] ; num /= base;
	}while ( num != 0 ); return( ptr );
	}