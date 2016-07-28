#include <stdlib.h>
#include <stdio.h>

	One can define the macro with a single, parenthesized "argument" which in the macro expansion becomes the entire argument list, parentheses and all, for a function such as printf():
	#define DEBUG(args) (printf("DEBUG: "), printf args) if(n != 0) DEBUG(("n is %d\n", n));
	The caller must always remember to use the extra parentheses. Other possible solutions are to use different macros depending on the number of arguments. C9X will introduce formal support for function-like macros with variable-length argument lists. The notation ... will appear at the end of the macro "prototype" (just as it does for varargs functions).
