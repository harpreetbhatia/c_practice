#include <stdlib.h>
#include <stdio.h>

	The segmentation fault, core dump, bus error kind of errors usually mean that the program tried to access memory it shouldn't have.
	Probable causes are overflow of local arrays; improper use of null pointers; corruption of the malloc() data structures; mismatched function arguments (specially variable argument functions like sprintf(), fprintf(), scanf(), printf()).
	For example, the following code is a sure shot way of inviting a segmentation fault in your program:
	sprintf(buffer, "%s %d", "Hello");
	So whats the difference between a bus error and a segmentation fault?
	A bus error is a fatal failure in the execution of a machine language instruction resulting from the processor
	detecting an anomalous condition on its bus. Such conditions include:
	-	Invalid address alignment (accessing a multi-byte number at an odd address).
	-	Accessing a memory location outside its address space.
	-	Accessing a physical address that does not correspond to any device.
	-	Out-of-bounds array references.
	-	References through uninitialized or mangled pointers.
	 
	A bus error triggers a processor-level exception, which Unix translates into a "SIGBUS" signal,which if not caught, will terminate the current process. It looks like a SIGSEGV, but the difference between the two is that SIGSEGV indicates an invalid access to valid memory, while SIGBUS indicates an access to an invalid address.
	Bus errors mean different thing on different machines. On systems such as Sparcs a bus error occurs when you access memory that is not positioned correctly.
	Maybe an example will help to understand how a bus error occurs
	#include < stdlib.h>
	#include < stdio.h> int main(void)
	{

	char *c; long int *i;
	c = (char *) malloc(sizeof(char)); c++;
	i = (long int *)c; printf("%ld", *i); return 0;
	}

	On Sparc machines long ints have to be at addresses that are multiples of four (because they are four bytes long), while chars do not (they are only one byte long so they can be put anywhere). The example code uses the char to create an invalid address, and assigns the long int to the invalid address. This causes a bus error when the long int is dereferenced.
	A segfault occurs when a process tries to access memory that it is not allowed to, such as the memory at address 0 (where NULL usually points). It is easy to get a segfault, such as the following example, which dereferences NULL.
	#include < stdio.h> int main(void)
	{

	char *p;
	 
	p = NULL;
	putchar(*p); return 0;
	}
