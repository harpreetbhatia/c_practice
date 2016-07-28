#include <stdlib.h>
#include <stdio.h>

	 
	Well, not always.
	In C, the array and pointer arithmetic is such that a pointer can be used to access an array or to simulate an array. What this means is whenever an array appears in an expression, the compiler automatically generates a pointer to the array's first element (i.e, &a[0]).
	There are three exceptions to this rule
	1.	When the array is the operand of the sizeof() operator.
	2.	When using the & operator.
	3.	When the array is a string literal initializer for a character array.
	Also, on a side note, the rule by which arrays decay into pointers is not applied recursively!. An array of arrays (i.e. a two-dimensional array in C) decays into a pointer to an array, not a pointer to a pointer.
	If you are passing a two-dimensional array to a function: int myarray[NO_OF_ROWS][NO_OF_COLUMNS]; myfunc(myarray);
	then, the function's declaration must match:
	void myfunc(int myarray[][NO_OF_COLUMNS])	or void myfunc(int (*myarray)[NO_OF_COLUMNS])
	Since the called function does not allocate space for the array, it does not need to know the overall size, so the number of rows, NO_OF_ROWS, can be omitted. The width of the array is still important, so the column dimension
	NO_OF_COLUMNS must be present.
	An array is never passed to a function, but a pointer to the first element of the array is passed to the function. Arrays are automatically allocated memory. They can't be relocated or resized later. Pointers must be assigned to allocated memory (by using (say) malloc), but pointers can be reassigned and made to point to other memory chunks.
	So, whats the difference between func(arr) and func(&arr)?
	In C, &arr yields a pointer to the entire array. On the other hand, a simple reference to arr returns a pointer to the first element of the array arr. Pointers to arrays (as in &arr) when subscripted or incremented, step over entire arrays, and are useful only when operating on arrays of arrays. Declaring a pointer to an entire array can be done like int (*arr)[N];, where N is the size of the array.
	Also, note that sizeof() will not report the size of an array when the array is a parameter to a function, simply because the compiler pretends that the array parameter was declared as a
	 
	pointer and sizeof reports the size of the pointer.
