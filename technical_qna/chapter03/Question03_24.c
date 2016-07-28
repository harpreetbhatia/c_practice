#include <stdlib.h>
#include <stdio.h>

// 	Try using pointers 
	struct MyStruct
	{

	int i; int j;
	};
	 
	int main()
	{

	struct MyStruct *p = 0;
	int size = ( ( char * ) ( p + 1 ) ) - ( ( char * ) p ) ; printf("\nSIZE : [%d]\nSIZE : [%d]\n", size); return 0;
	}