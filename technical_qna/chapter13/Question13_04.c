#include <stdlib.h>
#include <stdio.h>

	This is the wrong way of doing it.
	#define SQR(x) x*x
	Thats because, something like
	 
	#include stdio.h>
	#define SQR(x) x*x


	int main()
	{

	int i;
	i = 64/SQR(4);
	printf("[%d]",i); return(0);
	}

	will produce an output of 64, because of how macros work (The macro call square(4) will substituted by 4*4 so the expression becomes i = 64/4*4 . Since / and * has equal priority the expression will be evaluated as (64/4)*4 i.e. 16*4 = 64).
	This is the right way of doing it.
	#define SQR(x) ((x)*(x))
	But, if x is an expression with side effects, the macro evaluates them twice. The following is one way to do it while evaluating x only once.
	#include <math.h>
	#define SQR(x) pow((x),2.0)