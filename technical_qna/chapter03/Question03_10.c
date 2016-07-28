#include <stdlib.h>
#include <stdio.h>

	This is a very popular question
	You are given a large array X of integers (both positive and negative) and you need to find the maximum sum found in any contiguous subarray of X.
	Example X = [11, -12, 15, -3, 8, -9, 1, 8, 10, -2]
	Answer is 30.
	There are various methods to solve this problem, some are listed below
	Brute force maxSum = 0 for L = 1 to N
	{

	for R = L to N
	{

	sum = 0
	for i = L to R
	{
	 
	sum = sum + X[i]
	}

	maxSum = max(maxSum, sum)
	}
	}

	O(N^3)
	Quadratic
	Note that sum of [L..R] can be calculated from sum of [L..R-1] very easily. maxSum = 0
	for L = 1 to N
	{

	sum = 0
	for R = L to N
	{

	sum = sum + X[R]
	maxSum = max(maxSum, sum)
	}
	}

	Using divide-and-conquer
	O(N log(N)) maxSum(L, R)
	{

	if  L  >  R then
	return 0 if L  =  R then
	return max ( 0, X[ L ] ) M = ( L + R ) / 2
	 
	sum = 0 ; maxToLeft = 0 for i = M downto L do
	{

	sum = sum + X[ i ]
	maxToLeft = max ( maxToLeft, sum )
	}

	sum = 0; maxToRight = 0 for i = M to R do
	{

	sum = sum + X[i]
	maxToRight = max ( maxToRight ,  sum )
	}

	maxCrossing = maxLeft + maxRight; maxInA = maxSum( L , M )
	maxInB = maxSum( M+1 , R )
	return max ( maxCrossing , maxInA , maxInB )
	}

	Here is working C code for all the above cases
	#include<stdio.h>
	#define N 10
	int maxSubSum(int left, int right);
	int list[N] = {11, -12, 15, -3, 8, -9, 1, 8, 10, -2};
	int main()
	{

	int  i , j , k ;
	int  maxSum , sum ;
	/*---------------------------------------
	 
	* CUBIC - O(n*n*n)
	*---------------------------------------*/
	maxSum = 0;
	for( i = 0 ; i < N ;  i++ )
	{

	for( j = i ; j < N ; j++ )
	{

	sum = 0 ;
	for( k = i ; k < j ; k++ )
	{

	sum = sum + list[k];
	}

	maxSum  =  ( maxSum > sum ) ? maxSum : sum ;
	}
	}

	printf("\nmaxSum = [%d]\n", maxSum);
	/*-------------------------------------
	* Quadratic - O(n*n)
	* ------------------------------------ */
	maxSum = 0;
	for( i = 0 ; i < N ; i++ )
	{

	sum=0;
	for( j = i ; j < N ; j++ )
	{

	sum = sum + list[j];
	maxSum = ( maxSum > sum ) ? maxSum : sum;
	 
	}
	}

	printf("\nmaxSum = [%d]\n", maxSum);
	/*----------------------------------------
	* Divide and Conquer - O(nlog(n))
	* -------------------------------------- */
	printf("\nmaxSum : [%d]\n", maxSubSum(0,9)); return ( 0 ) ;
	}

	int maxSubSum(int left, int right)
	{

	int mid , sum , maxToLeft , maxToRight , maxCrossing , maxInA , maxInB ; int  i ;
	if ( left > right )
	{

	return 0;
	}

	if ( left == right )
	{

	return ( ( 0 > list[ left ] ) ? 0 : list[left] ) ;
	}

	mid = (left + right)/2; sum=0; maxToLeft=0;
	for( i = mid ; i >= left ; i-- )
	{

	sum = sum + list[i] ;
	 
	maxToLeft  =  ( maxToLeft > sum ) ? maxToLeft : sum ;
	}
	sum=0;

	maxToRight=0;
	for( i = mid + 1 ; i <= right ; i++ )
	{

	sum = sum + list[i];
	maxToRight = ( maxToRight > sum ) ? maxToRight : sum ;
	}

	maxCrossing = maxToLeft + maxToRight ; maxInA = maxSubSum ( left , mid ) ; maxInB = maxSubSum ( mid + 1, right ) ;
	return( ( ( maxCrossing > maxInA ) ? maxCrossing:maxInA ) > maxInB ? ( ( maxCrossing > maxInA ) ?maxCrossing:maxInA ) : maxInB ) ;
	}
	Note that, if the array has all negative numbers, then this code will return 0. This is wrong because it should return the maximum sum, which is the least negative integer in the array. This happens because we are setting maxSum to 0 initially. A small change in this code can be used to handle such cases.
