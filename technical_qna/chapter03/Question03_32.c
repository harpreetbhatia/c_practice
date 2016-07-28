#include <stdlib.h>
#include <stdio.h>

	double a, b; if( a  ==  b )
	{

	...
	}

	The above code might not work always. Thats because of the way floating point numbers are stored.
	A good way of comparing two floating point numbers is to have a accuracy threshold which is relative to the magnitude of the two floating point numbers being compared.
	#include <math.h>
	if ( fabs ( a  -  b )  <=  accurary_threshold  *  fabs ( a ) )
	There is a lot of material on the net to know how floating point numbers can be compared. Got for it if you really want to understand.
	Another way which might work is something like this. I have not tested it! int compareFloats ( float f1 ,  float f2 )
	{

	char *b1, *b2 ; int i ;
	b1 = ( char * ) &f1 ; b2  =  ( char * ) &f2 ;
	/* Assuming sizeof(float) is 4 bytes) */ for ( i = 0  ;  i < 4  ;  i++, b1++, b2++ )
	{

	if ( *b1  !=  *b2 )
	{

	return(NOT_EQUAL); /* You must have defined this before */
	 
	}
	}

	return(EQUAL);
	}
