#include <stdlib.h>
#include <stdio.h>

	Its pretty simple to do this in the C language if you know how to use C pointers. Here are some example C code snipptes....
	One dimensional array
	int *myarray = malloc(no_of_elements * sizeof(int));
	//Access elements as myarray[i] Two dimensional array Method1
	int **myarray = ( int ** ) malloc( no_of_rows * sizeof( int * ) ) ; for( i = 0 ; i < no_of_rows ; i++ )
	{

	myarray[i] = malloc( no_of_columns * sizeof( int ) );
	}

	// Access elements as myarray[i][j]
	Method2 (keep the array's contents contiguous)
	int **myarray = ( int ** ) malloc( no_of_rows * sizeof( int * ) ); myarray[0] = malloc(no_of_rows * no_of_columns * sizeof( int ) ); for( i = 1; i <  no_of_rows ; i++)
	myarray[i] = myarray[0] + ( i * no_of_columns ) ;
	// Access elements as myarray[i][j]
	Method3
	int *myarray = malloc( no_of_rows * no_of_columns * sizeof( int ) ) ;
	 
	// Access elements using myarray[ i * no_of_columns + j ].
	Three dimensional array
	#define MAXX 3
	#define MAXY 4
	#define MAXZ 5 main()
	{

	int ***p,i,j;
	p=( int *** ) malloc( MAXX * sizeof( int *** ) ); for(i=0;i<MAXX;i++)
	{

	p[i]=( int ** )malloc( MAXY * sizeof( int * ) ); for( j=0 ; j < MAXY ; j++ )
	p[i][j]=( int * ) malloc( MAXZ * sizeof( int ) );
	}

	for(k=0;k<MAXZ;k++)
	for(i=0;i<MAXX;i++)
	for(j=0;j<MAXY;j++)
	p[i][j][k]= < something > ;
	}