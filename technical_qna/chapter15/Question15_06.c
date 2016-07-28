#include <stdlib.h>
#include <stdio.h>

	Here is some sample C code. The idea is to check the bytes in the file to see if they are ASCII or not...
	#include <stdio.h>
	int main(int argc, char *argv[])
	{

	unsigned char ch; FILE *file;
	int binaryFile = FALSE;
	 

	time.
	 
	file = fopen(<FILE_PATH>, "rb");	// Open in Binary mode for the first

	while((fread(&ch, 1, 1, file) == 1) && (binaryFile == FALSE))
	{
	 

	if(ch < 9 || ch == 11 || (ch > 13 && ch < 32) || ch == 255)
	{

	binaryFile = 1;
	}
	}

	fclose(file); if(binaryFile)
	file = fopen(<FILE_PATH>, "rb");

	else
	file = fopen(<FILE_PATH>, "r");

	if(binaryFile)
	{

	while(fread(&ch, 1, 1, file) == 1)
	{

	// Do whatever you want here with the binary file byte...
	}
	}
	else
	{

	while(fread(&ch, 1, 1, file) == 1)
	{

	// This is ASCII data, can easily print it! putchar(ch);
	}
	 
	}
	fclose(file); return(0);
	}