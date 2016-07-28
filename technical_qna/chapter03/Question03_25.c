#include <stdlib.h>
#include <stdio.h>

// 	Are you sure you know this? A lot of people think they already know this, but guess what? So take a good look at this C program. Its asked in most of the interviews as a warm up question.
	// Matrix A (m*n)
	// Matrix B (n*k)
	// Matrix C (m*k) for(i=0; i<m; i++)
	{

	for(j=0;j<k;j++)
	{

	c[i][j] = 0 ;
	for( l = 0 ; l < n ; l++ )
	c[i][j] += a[i][l] * b[l][j];
	}
	}