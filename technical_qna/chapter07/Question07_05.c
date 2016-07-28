#include <stdlib.h>
#include <stdio.h>

	Before ANSI C introduced the void * generic pointer, these casts were required because older compilers used to return a char pointer.
	int *myarray;
	myarray = (int *)malloc(no_of_elements * sizeof(int));
	But, under ANSI Standard C, these casts are no longer necessary as a void pointer can be assigned to any pointer. These casts are still required with C++, however.
