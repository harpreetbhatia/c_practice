#include <stdlib.h>
#include <stdio.h>

	Lets first refresh ourselves with the Fibonacci sequence 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, .....
	Fibonacci numbers obey the following rule F(n) = F(n-1) + F(n-2)
	Here is an iterative way to generate fibonacci numbers and also return the nth number. int fib( int n )
	{

	int f[n+1];
	 
	f[1] = f[2] = 1;
	printf("\nf[1] = %d", f[1]);
	printf("\nf[2] = %d", f[2]); for ( int i = 3 ; i <= n ; i++ )
	{

	f[i] = f[i-1] + f[i-2]; printf("\nf[%d] = [%d]",i,f[i]);
	}

	return f[n];
	}

	Here is a recursive way to generate fibonacci numbers. int fib(int n)
	{
	if ( n <= 2 )
	return 1;

	 
	else


	}
	 


	return fib(n-1) + fib(n-2);
	 

	Here is an iterative way to just compute and return the nth number (without storing the previous numbers).
	int fib(int n)
	{

	int a = 1, b = 1;
	for ( int i = 3 ; i <= n ;  i++ )
	{

	int c = a + b; a = b;
	b = c;
	 
	}
	return a;
	}

	There are a few slick ways to generate fibonacci numbers, a few of them are listed below
	Method1
	If you know some basic math, its easy to see that n
	[ 1 1 ]	=   [ F(n+1) F(n)  ]
	[ 1 0 ]	[ F(n)   F(n-1) ]
	or
	(f(n) f(n+1)) [ 0 1 ] = (f(n+1) f(n+2)) [ 1 1 ]
	or
	n

	(f(0) f(1)) [ 0 1 ] = (f(n) f(n+1)) [ 1 1 ]
	The n-th power of the 2 by 2 matrix can be computed efficiently in O(log n) time. This implies an O(log n) algorithm for computing the n-th Fibonacci number.
	Here is the pseudocode for this int Matrix[2][2] = {{1,0}{0,1}}
	int fib(int n)
	{

	matrixpower( n - 1 ) ; return  Matrix[0][0] ;
	}

	void matrixpower(int n)
	{

	if ( n > 1 )
	 
	{
	matrixpower( n / 2 ) ; Matrix = Matrix * Matrix ;
	}

	if (n is odd)
	{
	Matrix = Matrix * {{1,1}{1,0}}
	}
	}

	And here is a program in C which calculates fib(n)
	#include<stdio.h>
	int M[2][2]={{1,0},{0,1}};
	int A[2][2]={{1,1},{1,0}};
	int C[2][2]={{0,0},{0,0}}; // Temporary matrix used for multiplication. void matMul(int n);
	void mulM(int m); int main()
	{

	int n; n=6;
	matMul( n - 1 ) ;
	// The nth fibonacci will be stored in M[0][0] printf("\n%dth Fibonaci number : [%d]\n\n", n, M[0][0]); return ( 0 );
	}

	// Recursive function with divide and conquer strategy void matMul ( int n )
	 
	{
	if ( n > 1 )
	{

	matMul ( n / 2 ) ;
	mulM ( 0 ) ;	// M * M
	}

	if( n % 2 != 0 )
	{

	mulM ( 1 ) ;	//  M * {{1,1}{1,0}}
	}
	}

	// Function which does some basic matrix multiplication. void mulM(int m)
	{

	int i,j,k;
	if ( m == 0 )
	{

	// C = M * M
	for( i = 0 ; i < 2 ; i++ )
	for( j = 0 ; j < 2 ; j++ )
	{

	 







	}
	else
	 
	C[i][j] = 0 ;
	for( k = 0 ; k < 2 ; k++ ) C[i][j] += M[i][k] * M[k][j] ;
	}
	 
	{
	// C = M * {{1,1}{1,0}}
	for( i = 0 ; i < 2 ; i++ )
	for(j=0;j<2;j++)
	{

	C[i][j]=0;
	for( k = 0 ; k < 2 ; k++ ) C[i][j] += A[i][k] * M[k][j] ;
	}
	}

	// Copy back the temporary matrix in the original matrix M for( i = 0 ; i < 2 ; i++ )
	for( j = 0 ; j < 2 ; j++ )
	{

	M[i][j] = C[i][j] ;
	}
	}
	Method2

	f ( n ) = ( 1 / sqrt ( 5 ) ) * ( ( ( 1 + sqrt ( 5 ) ) / 2 ) ^ n - ( ( 1 - sqrt ( 5 ) ) / 2 ) ^ n )     So now, how does one find out if a number is a fibonacci or not?.
	The cumbersome way is to generate fibonacci numbers till this number and see if this number is one of them. But there is another slick way to check if a number is a fibonacci number or not.
	N is a Fibonacci number if and only if ( 5 * N * N + 4 ) or ( 5 * N * N - 4 ) is a perfect square!
	Dont believe me?
	3 is a Fibonacci number since (5*3*3 + 4) is 49 which is 7*7
	5 is a Fibonacci number since (5*5*5 - 4) is 121 which is 11*11
	4 is not a Fibonacci number since neither (5*4*4 + 4) = 84 nor (5*4*4 - 4) = 76 are
	 
	perfect squares.
	To check if a number is a perfect square or not, one can take the square root, round it to the nearest integer and then square the result. If this is the same as the original whole number then the original was a perfect square.
