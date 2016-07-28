#include <stdlib.h>
#include <stdio.h>

	This is the correct way to write a multi statement macro.
	#define MYMACRO(argument1, argument2) do { \ stament1; \
	stament2; \
	} while(1) /* no trailing semicolon */