#include <stdlib.h>
#include <stdio.h>

// 	The prototype of the strlen() function is... size_t strlen(const char *string);
	 
// 	Here is some C code which implements the strlen() function.... int my_strlen(char *string)
	{

	int length;
	for (length = 0; *string != '\0', string++)
	{

	length++;
	}

	return(length);
	}

	Also, see another example int my_strlen(char *s)
	{

	char *p=s; while(*p!='\0')
	p++;
	return(p-s);
	}