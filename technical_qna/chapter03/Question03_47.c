#include <stdlib.h>
#include <stdio.h>

// 	Try this out
	isSubset( char *a , char *b )
	{

	int letterPresent[256]; int i;
	for( i = 0 ; i < 256 ; i++ )
	letterPresent[i]=0; for( i = 0 ; a[i] != '\0' ; i++ )
	letterPresent[ a[i] ]++;
	 
	for( i = 0 ; b[i] != '\0' ; i++ )
	if( letterPresent[ b[i] ] ) return( FALSE );
	return( TRUE );
	}
