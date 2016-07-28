#include <stdlib.h>
#include <stdio.h>


// 	One more most frequently asked interview question!.
// 	memmove() offers guaranteed behavior if the source and destination arguments overlap. 
// memcpy() makes no such guarantee, and may therefore be more efficient to implement. 
// It's always safer to use memmove().
// 	Note that the prototype of memmove() is ...

	void *memmove(void *dest, const void *src, size_t count); Here is an implementation..

	#include <stdio.h>
	#include <string.h>
	void *mymemmove(void *dest, const void *src, size_t count); int main(int argc, char* argv[])
	{
	char *p1, *p2;
	 
	char *p3, *p4; int size;
	printf("\n--------------------------------\n");
	-------------
	*
	*	CASE 1 : From (SRC) < To (DEST)
	*
	* +--+---------------------+--+
	* | | | |
	* +--+---------------------+--+
	* ^ ^
	* | |
	*	From To
	*
	* --------------------------------------- */

	p1 = (char *) malloc(12); memset(p1,12,'\0'); size=10;

	strcpy(p1,"ABCDEFGHI"); p2 = p1 + 2;
	printf("\n--------------------------------\n");
	printf("\nFrom (before) = [%s]",p1);
	printf("\nTo (before) = [%s]",p2); mymemmove(p2,p1,size);
	printf("\n\nFrom (after) = [%s]",p1); printf("\nTo (after) = [%s]",p2);

	printf("\n--------------------------------\n");

// 	----------------------------------------
// 	CASE 2 : From (SRC) > To (DEST)
// 	----------------------------------------


	p3 = (char *) malloc(12); memset(p3,12,'\0');
	p4 = p3 + 2;
	strcpy(p4, "ABCDEFGHI"); printf("\nFrom (before) = [%s]",p4);
	printf("\nTo (before) = [%s]",p3); mymemmove(p3, p4, size);
	printf("\n\nFrom (after) = [%s]",p4); printf("\nTo (after) = [%s]",p3);

	printf("\n--------------------------------\n");

	/* ----------------------------------------
	*
	* CASE 3 : No overlap
	*
	* --------------------------------------- */

	p1 = (char *) malloc(30); memset(p1,30,'\0'); size=10;

	strcpy(p1,"ABCDEFGHI"); p2 = p1 + 15;

	printf("\n--------------------------------\n");
	printf("\nFrom (before) = [%s]",p1);
	printf("\nTo (before) = [%s]",p2); mymemmove(p2,p1,size);
	printf("\n\nFrom (after) = [%s]",p1); printf("\nTo (after) = [%s]",p2);

	printf("\n--------------------------------\n");

	printf("\n\n");

	return 0;
	}
	 

	void *mymemmove(void *to, const void *from, size_t size)
	{
	unsigned char *p1;
	const unsigned char *p2;

	p1 = (unsigned char *) to;
	p2 = (const unsigned char *) from; p2 = p2 + size;
	// Check if there is an overlap or not. while (p2 != from && --p2 != to);


	if (p2 != from)
	{
	// Overlap detected!

	p2 = (const unsigned char *) from; p2 = p2 + size;
	p1 = p1 + size;

	while (size-- != 0)
	{
	*--p1 = *--p2;
	}
	}
	else
	{
	// No overlap OR they overlap as CASE 2 above.
	// memcopy() would have done this directly.

	while (size-- != 0)
	{
	*p1++ = *p2++;
	}
	}

	return(to);
	}

// 	And here is the output
// 	--------------------------------
// 	From (before) = [ABCDEFGHI] To (before) = [CDEFGHI]
	 
// 	From (after) = [ABABCDEFGHI] To (after) = [ABCDEFGHI]
// 	--------------------------------
// 	From (before) = [ABCDEFGHI] To (before) = [α╙ABCDEFGHI]

// 	From (after) = [CDEFGHI] To (after) = [ABCDEFGHI]

// 	--------------------------------

// 	From (before) = [ABCDEFGHI] To (before) = [FEδ‼&:F]

// 	From (after) = [ABCDEFGHI] To (after) = [ABCDEFGHI]

// 	--------------------------------
// 	So then, whats the difference between the implementation of memmove() and memcpy(). 
// Its just that memcpy() will not care if the memories overlap and will either copy 
// from left to right or right to left without checking which method to used depending 
// on the type of the overlap. Also note that the C code proves that the results are the 
// same irrespective of the Endian-ness of the machine.