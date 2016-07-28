#include <stdlib.h>
#include <stdio.h>

	The header stdarg.h provides this functionality. All functions like printf(), scanf() etc use this functionality.
	The program below uses a var_arg type of function to count the overall length of strings passed to the function.
	#include <stdarg.h>
	int myfunction(char *first_argument,...)
	{

	int length; va_list argp;
	va_start(argp, first); char *p;
	length = strlen(first_argument);
	while((p = va_arg(argp, char *)) != NULL)
	{
	 
	length = length + strlen(p);
	}

	va_end(argp); return(length);
	}

	int main()
	{

	int length;
	length = myfunction("Hello","Hi","Hey!",(char *)NULL); return(0);
	}

	How can I find how many arguments a function was passed?
	Any function which takes a variable number of arguments must be able to determine from the arguments themselves, how many of them there have been passed. printf() and some similar functions achieve this by looking for the format string. This is also why these functions fail badly if the format string does not match the argument list. Another common technique, applicable when the arguments are all of the same type, is to use a sentinel value (often 0, -1, or an appropriately-cast null pointer) at the end of the list. Also, one can pass an explicit count of the number of variable arguments. Some older compilers did provided a nargs() function, but it was never portable.
	Is this allowed?
	int f(...)
	{

	...
	}

	No! Standard C requires at least one fixed argument, in part so that you can hand it to va_start().
	So how do I get floating point numbers passed as arguments?
	Arguments of type float are always promoted to type double, and types char and short int are promoted to int. Therefore, it is never correct to invoke
	va_arg(argp, float);
	 
	instead you should always use va_arg(argp, double)
	Similarly, use va_arg(argp, int)
	to retrieve arguments which were originally char, short, or int.
	How can I create a function which takes a variable number of arguments and passes them to some other function (which takes a variable number of arguments)?
	You should provide a version of that other function which accepts a va_list type of pointer.
	So how can I call a function with an argument list built up at run time?
	There is no portable way to do this. Instead of an actual argument list, you might want to pass an array of generic (void *) pointers. The called function can then step through the array, much like main() steps through char *argv[].
	What is the use of vprintf(), vfprintf() and vsprintf()?
	Below, the myerror() function prints an error message, preceded by the string "error: " and terminated with a newline:
	#include <stdio.h>
	#include <stdarg.h>
	void myerror(char *fmt, ...)
	{

	va_list argp; fprintf(stderr, "error: "); va_start(argp, fmt); vfprintf(stderr, fmt, argp); va_end(argp); fprintf(stderr, "\n");
	}
