#include <stdlib.h>
#include <stdio.h>

	Upon a successful return, the printf() function returns the number of characters printed (not including the trailing '\0' used to end output to strings). If the output was truncated due to this limit then the return value is the number of characters (not including the trailing '\0') which would have been written to the final string if enough space had been available. Thus, a return value of size or more means that the output was truncated. If an output error is encountered, a negative value is returned.
	There is a very funny yet interesting interview question around this.... Look at the code below.
	void main()
	{

	 
	if(X)
	{


	}
	else
	{


	}
	 



	printf("Hello");






	printf(" World");
	 
	}
	What should X be replaced with inorder to get the output as "Hello World"? And here comes the answer....
	#include <stdio.h> int main()
	{

	if(!printf("Hello"))
	{

	 


	}
	else
	{


	}
	}
	 
	printf("Hello");






	printf(" World");
	 

	Kind of stupid isn't it? But they do ask these type of questions. Believe me!