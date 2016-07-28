#include <stdlib.h>
#include <stdio.h>

	Here is a C program to implement the strdup() function. char *mystrdup(char *s)
	{

	char *result = (char*)malloc(strlen(s) + 1); if (result == (char*)0)
	{

	return (char*)0;
	}

	strcpy(result, s); return result;
	}