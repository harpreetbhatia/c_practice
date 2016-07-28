#include <stdlib.h>
#include <stdio.h>

	Unlike fgets(), gets() cannot be told the size of the buffer it's to read into, so it cannot be prevented from overflowing that buffer. As a general rule, always use fgets(). fgets() also takes in the size of the buffer, so that the end of the array cannot be overwritten.
	fgets(buffer, sizeof(buffer), stdin); if((p = strchr(buffer, '\n')) != NULL)
	{

	*p = '\0';
	}

	Also, fgets() does not delete the trailing "\n", as gets(). So whats the right way to use fgets() when reading a file? while(!feof(inp_file_ptr))
	{

	fgets(buffer, MAX_LINE_SIZE, inp_file_ptr); fputs(buffer, out_file_ptr);
	}

	The code above will copy the last line twice! This is because, in C, end-of-file is only indicated after an input routine has tried to read, and failed. We should just check the return value of the input routine (in this case, fgets() will return NULL on end-of-file); often, you don't need to use feof() at all.
	This is the right way to do it
	while(fgets(buffer, MAX_LINE_SIZE, inp_file_ptr))
	{

	fputs(buffer, out_file_ptr);
	 
	}