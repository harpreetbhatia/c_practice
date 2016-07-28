#include <stdlib.h>
#include <stdio.h>

	First lets look at the prototypes of these two popular functions..
	 
	#include <stdlib.h>
	void *calloc(size_t n, size_t size); void *malloc(size_t size);
	The two functions malloc() and calloc() are functionally same in that they both allocate memory from a storage pool (generally called heap). Actually, the right thing to say is that these two functions are memory managers and not memory allocators. Memory allocation is done by OS specific routines (like brk() and sbrk()). But lets not get into that for now...
	Here are some differences between these two functions..
	*	malloc() takes one argument, whereas calloc() takes two.
	*	calloc() initializes all the bits in the allocated space to zero (this is all-bits-zero!, where as malloc() does not do this.
	*	A call to calloc() is equivalent to a call to malloc() followed by one to memset(). calloc(m, n)
	is essentially equivalent to p = malloc(m * n); memset(p, 0, m * n);
	Using calloc(), we can carry out the functionality in a faster way than a combination of malloc() and memset() probably would. You will agree that one libray call is faster than two calls. Additionally, if provided by the native CPU, calloc() could be implementated by the CPU's "allocate-and-initialize-to-zero" instruction.
	*	The reason for providing the "n" argument is that sometimes it is required to allocate a number ("n") of uniform objects of a particular size ("size"). Database application, for instance, will have such requirements. Proper planning for the values of "n" and "size" can lead to good memory utilization.
