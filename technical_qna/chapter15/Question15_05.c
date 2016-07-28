#include <stdlib.h>
#include <stdio.h>

	Whew!, thats a huge list. fopen()
	This function is used to open a stream. FILE *fp;
	fp = fopen("filename","mode"); fp = fopen("data","r");
	fp = fopen("results","w");
	Modes
	"r"	-> Open for reading. "w"		-> Open for writing. "a"	-> Open for appending.
	"r+"	-> Both reading and writing.
	"w+"		-> Both reading and writing, create new file if it exists, "a+"	-> Open for both reading and appending.
	fopen()
	fclose() is used to close a stream . fclose(fp);
	putc(), getc(), putw(), getw(), fgetc(), getchar(), putchar(), fputs()
	These functions are used to read/write different types of data to the stream. putc(ch,fp);
	c=getc(fp); putw(integer, fp); integer=getw(fp); fprintf(), fscanf()
	 
	Read/Write formatted data from/to the stream. fprintf(fp,"control string",list); fscanf(fp,"control string", list);
	foef()
	Check the status of a stream if(feof(fp)!=0)
	ftell(), fseek(), rewind(), fgetpos(), fsetpos()
	Reposition the file pointer of a stream
	n=ftell(fp); //Relative offset (in bytes) of the current position. rewind(fp);
	fseek(fp, offset, position); Position can be
	0->start of file
	1->current position 2->end of file
	fseek(fp,0L,0); // Same as rewind. fseek(fp,0L,1); // Stay at current position. fseek(fp,0L,2); // Past end of file. fseek(fp,m,0); // Move to (m+1) byte. fseek(fp,m,1)	// Go forward m bytes.
	fseek(fp,-m,1); // Go backward m bytes from current position. fseek(fp,-m,2);   //  Go  backward  from  end  of  file.    fread(), fwrite()
	Binary stream input/output. fwrite(&customer, sizeof(record),1,fp); fread(&customer,sizeof(record),1,fp);
	Here is a simple piece of code which reads from a file
	 
	#include <stdio.h>
	#include <conio.h> int main()
	{

	FILE *f;
	char buffer[1000];
	f=fopen("E:\\Misc\\ Temp\\FileDrag\\Main.cpp","r"); if(f)
	{

	printf("\nOpenened the file!\n"); while(fgets(buffer,1000,f))
	{

	printf("(%d)-> %s\n",strlen(buffer),buffer);
	}
	}

	fclose(f); getch(); return(0);
	}
