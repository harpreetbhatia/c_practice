#include <stdlib.h>
#include <stdio.h>

	A null pointer simply means "I am not allocated yet!" and "I am not pointing to anything yet!".
	The C language definition states that for every available pointer type, there is a special value which is called the null pointer. It is guaranteed to compare unequal to a pointer to any object or function.
	A null pointer is very different from an uninitialized pointer. A null pointer does not point to any object or function; but an uninitialized pointer can point anywhere.
	There is usually a null pointer for each type of a pointer, and the internal values of these null pointers for different pointer types may be different, its up to the compiler. The & operator will never yield a null pointer, nor will a successful call to malloc() (malloc() does return a null pointer when it fails).
	execl("/bin/ls", "ls", "-l", (char *)0);
	In this call to execl(), the last argument has been explicitly casted to force the 0 to be treated as a pointer.
	Also, if ptr is a pointer then if( ptr ) { }
	and
	if( !ptr ) { }
	are perfectly valid.
	How is NULL defined?, you may ask.
	ANSI C allows the following definition
	#define NULL ((void *)0)
	NULL and 0 are interchangeable in pointer contexts.
	Make sure you are able to distinguish between the following : the null pointer, the internal representation of a null pointer, the null pointer constant (i.e, 0), the NULL macro, the ASCII null character (NUL), the null string ("").
