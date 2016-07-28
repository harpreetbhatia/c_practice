#include <stdlib.h>
#include <stdio.h>

	Deleting a file
	The Standard C Library function is remove(). If thats not there, use unlink(). Copying a file
	Directly use system() to invoke the operating system's copy() utility, or open the source and destination files, read characters or blocks of characters from the source file, and write them to the destination file.
	How to read directories?
	 
	Use the opendir() and readdir() functions, which are part of the POSIX standard and are available on most Unix variants.
