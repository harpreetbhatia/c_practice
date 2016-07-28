#include <stdlib.h>
#include <stdio.h>

	ANSI has introduced a well-defined token-pasting operator, ##, which can be used like this:
	#define f(g,g2) g##g2 main()
	{

	 



	}
	O/P 100
	 
	int var12=100; printf("%d",f(var,12));
	 
	Stringizing operator
	#define sum(xy) printf(#xy " = %f\n",xy);
	 
	main()
	{


	}
	 



	sum(a+b); // As good as printf("a+b = %f\n", a+b);
	 

	So what does the message "warning: macro replacement within a string literal" mean?
	#define TRACE(var, fmt) printf("TRACE: var = fmt\n", var) TRACE(i, %d);
	gets expanded as printf("TRACE: i = %d\n", i);
	In other words, macro parameters were expanded even inside string literals and character constants. Macro expansion is *not* defined in this way by K&R or by Standard C. When you do want to turn macro arguments into
	strings, you can use the new # preprocessing operator, along with string literal concatenation:
	#define TRACE(var, fmt) printf("TRACE: " #var " = " #fmt "\n", var)
	See and try to understand this special application of the strigizing operator!
	#define Str(x) #x
	#define Xstr(x) Str(x)
	#define OP plus
	char *opname = Xstr(OP); //This code sets opname to "plus" rather than "OP". Here are some more examples
	Example1
	Define a macro DEBUG such that the following program int main()
	{

	int x=4;
	float a = 3.14; char ch = 'A'; DEBUG(x, %d);
	 



	}
	outputs
	 
	DEBUG(a, %f);
	DEBUG(ch, %c);
	 

	DEBUG: x=4 DEBUG: y=3.140000 DEBUG: ch=A
	The macro would be
	#define DEBUG(var, fmt) printf("DEBUG:" #var "=" #fmt "\n", var); Example2
	Write a macro PRINT for the following program int main()
	{

	int x=4, y=4, z=5; int a=1, b=2, c=3; PRINT(x,y,z);
	PRINT(a,b,c);
	}

	such that it outputs x=4 y=4 z=5
	a=1 b=2 c=3
	Here is a macro that will do this
	#define PRINT(v1,v2,v3) printf("\n" #v1 "=%d" #v2 "=%d" #v3 "=%d", v1, v2, v3);
