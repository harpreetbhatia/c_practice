#include <stdlib.h>
#include <stdio.h>

	strtok() is the only standard function available for "tokenizing" strings.
	The strtok() function can be used to parse a string into tokens. The first call to strtok() should have the string as its first argument. Subsequent calls should have the first argument set to NULL. Each call returns a pointer to the next token, or NULL when no more tokens are found. If a token ends with a delimiter, this delimiting character is overwritten with a "\0" and a pointer to the next character is saved for the next call to strtok(). The delimiter string delim may be different for each call.
	The strtok_r() function works the same as the strtok() function, but instead of using a static buffer it uses a pointer to a user allocated char* pointer. This pointer must be the same while parsing the same string.
	An example main()
	{

	char str[]="This is a test"; char *ptr[10];
	char *p; int i=1; int j;
	p=strtok(str," "); if(p!=NULL)
	{

	ptr[0]=p; while(1)
	 
	{
	p=strtok(NULL, " "); if(p==NULL)
	break;

	 
	else
	{




	}
	}
	}
	 



	ptr[i] = p; i++;
	 

	for(j=0;j<i;j++)
	{

	printf("\n%s\n", ptr[i]);
	}
	}