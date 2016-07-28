#include <stdlib.h>
#include <stdio.h>

	malloc() is used to allocate memory. Its a memory manager.
	calloc(m, n) is also used to allocate memory, just like malloc(). But in addition, it also zero fills the allocated memory area. The zero fill is all-bits-zero. calloc(m.n) is essentially equivalent to
	p = malloc(m * n); memset(p, 0, m * n);
	The malloc() function allocates raw memory given a size in bytes. On the other hand, calloc() clears the requested memory to zeros before return a pointer to it. (It can also compute the request size given the size of the base data structure and the number of them desired.)
	The most common source of problems with malloc() are
	1.	Writing more data to a malloc'ed region than it was allocated to hold.
	2.	malloc(strlen(string)) instead of (strlen(string) + 1).
	3.	Using pointers to memory that has been freed.
	4.	Freeing pointers twice.
	5.	Freeing pointers not obtained from malloc.
	6.	Trying to realloc a null pointer. How does free() work?
	Any memory allocated using malloc() realloc() must be freed using free(). In general, for every call to malloc(), there should be a corresponding call to free(). When you call free(), the memory pointed to by the passed pointer is freed. However, the value of the pointer in
	 
	the caller remains unchanged. Its a good practice to set the pointer to NULL after freeing it to prevent accidental usage. The malloc()/free() implementation keeps track of the size of each block as it is allocated, so it is not required to remind it of the size when freeing it using free(). You can't use dynamically-allocated memory after you free it.
	Is there a way to know how big an allocated block is?
	Unfortunately there is no standard or portable way to know how big an allocated block is using the pointer to the block!. God knows why this was left out in C.
	Is this a valid expression? pointer = realloc(0, sizeof(int)); Yes, it is!
