#include <stdlib.h>
#include <stdio.h>

// 	Here is a C program which implements the substr() function in C. int main()
	 
	{
	char str1[] = "India"; char str2[25]; substr(str2, str1, 1, 3);
	printf("\nstr2 : [%s]", str2); return(0);
	}

	substr(char *dest, char *src, int position, int length)
	{

	dest[0]='\0';
	strncat(dest, (src + position), length);
	}