#include <stdlib.h>
#include <stdio.h>

	There are many ways one can implement the strcmp() function. Note that strcmp (str1,str2) returns a -ve number if str1 is alphabetically above str2, 0 if both are equal and
	+ve if str2 is alphabetically above str1.
	Here are some C programs which implement the strcmp() function. This is also one of the most frequently asked interview questions. The prototype of strcmp() is
	int strcmp( const char *string1, const char *string2 ); Here is some C code..
	 
	#include <stdio.h>
	int mystrcmp(const char *s1, const char *s2); int main()
	{

	printf("\nstrcmp() = [%d]\n", mystrcmp("A","A"));
	printf("\nstrcmp() = [%d]\n", mystrcmp("A","B"));
	printf("\nstrcmp() = [%d]\n", mystrcmp("B","A")); return(0);
	}

	int mystrcmp(const char *s1, const char *s2)
	{

	while (*s1==*s2)
	{

	if(*s1=='\0') return(0); s1++;
	s2++;
	}

	return(*s1-*s2);
	}

	And here is the output... strcmp() = [0]
	strcmp() = [-1]
	strcmp() = [1]