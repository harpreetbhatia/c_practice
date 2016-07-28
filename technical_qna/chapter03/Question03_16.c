#include <stdlib.h>
#include <stdio.h>

// 	This is one of the most famous interview questions One of the famous C programs is...

	char *s = "char *s = %c%s%c ; main( ) { printf ( s , 34 , s , 34 ) ; } " ; main( ){ printf    ( s ,34 , s , 34 ) ; }
	
// 	So how does it work?
// 	It's not difficult to understand this program. In the following statement, printf ( f , 34 , f , 34 ,10 ) ;
// 	the parameter "f" not only acts as the format string, but also as a value for the %s specifier. The ASCII value of double quotes is 34, and that of new-line is 10. With these fact ready, the solution is just a matter of tracing the program.
