#include <stdlib.h>
#include <stdio.h>

	The right declaration of main() is
	int main(void)	or
	int main(int argc, char *argv[])	or
	int main(int argc, char *argv[], char *env[])  //Compiler dependent, non-standard C.
	In C, main() cannot return anything other than an int.Something like void main()
	is illegal. There are only three valid return values from main() - 0, EXIT_SUCCESS, and EXIT_FAILURE, the latter two are defined in <stdlib.h>.
	Something like this can cause unpredicted behavior struct mystruct
	{

	int value;
	struct mystruct *next;
	}

	main(argc, argv)
	{ ... }
	Here the missing semicolon after the structure declaration causes main to be misdeclared.
