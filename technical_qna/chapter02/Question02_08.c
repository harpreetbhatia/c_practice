#include <stdlib.h>
#include <stdio.h>

	Here is some C code that simulates a file copy action.
	#include <stdio.h>	/* standard I/O routines. */
	#define MAX_LINE_LEN 1000 /* maximum line length supported. */ void main(int argc, char* argv[])
	{

	char* file_path_from; char* file_path_to; FILE* f_from;
	FILE* f_to;
	char buf[MAX_LINE_LEN+1]; file_path_from = "<something>"; file_path_to = "<something_else>"; f_from = fopen(file_path_from, "r"); if (!f_from)
	 
	{
	exit(1);
	}

	f_to = fopen(file_path_to, "w+"); if (!f_to) {exit(1);}
	/* Copy source to target, line by line. */
	while (fgets(buf, MAX_LINE_LEN+1, f_from))
	{

	if (fputs(buf, f_to) == EOF)
	{

	exit(1);
	}
	}

	if (!feof(f_from))
	{

	exit(1);
	}

	if (fclose(f_from) == EOF)
	{

	exit(1);
	}

	if (fclose(f_to) == EOF)
	{

	exit(1);
	}

	return(0);
	}