#include <stdlib.h>
#include <stdio.h>

	There is a lot of difference! char a[] = "string";
	char *a = "string";
	The declaration char a[] asks for space for 7 characters and see that its known by the name "a". In contrast, the declaration char *a, asks for a place that holds a pointer, to be known by the name "a". This pointer "a" can point anywhere. In this case its pointing to an anonymous array of 7 characters, which does have any name in particular. Its just present in memory with a pointer keeping track of its location.
	char a[] = "string";
	+----+----+----+----+----+----+------+
	a: | s  | t |  r |  i |  n | g | '\0'  |
	+----+----+----+----+----+----+------+ a[0] a[1] a[2] a[3] a[4] a[5] a[6]

	char *a = "string";
	+-----+	+---+---+---+---+---+---+------+
	| a: | *======> | s | t | r | i | n | g | '\0' |
	+-----+	+---+---+---+---+---+---+------+
	Pointer	Anonymous array
	It is curcial to know that a[3] generates different code depending on whether a is an array or a pointer. When the compiler sees the expression a[3] and if a is an array, it starts at the location "a", goes three elements past it, and returns the character there. When it sees the expression a[3] and if a is a pointer, it starts at the location "a", gets the pointer value there, adds 3 to the pointer value, and gets the character pointed to by that value.
	If a is an array, a[3] is three places past a. If a is a pointer, then a[3] is three places past
	 
	the memory location pointed to by a. In the example above, both a[3] and a[3] return the same character, but the way they do it is different!
	Doing something like this would be illegal. char *p = "hello, world!";
	p[0] = 'H';