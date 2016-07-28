#include <stdlib.h>
#include <stdio.h>

// 	Here is a C function
	int binarySearch( int arr[] , int size , int item )
	{

	int left , right , middle ; left  = 0;
	right = size-1; while( left <= right )
	{

	middle = ( ( left + right ) / 2 ) ; if( item == arr[middle] )
	{

	return( middle );
	}

	if( item  > arr[middle] )
	{

	 


	}
	else
	{


	}
	}
	 
	left  = middle+1;






	right = middle-1;
	 

	return(-1);
	}

// 	Note that the Binary Search algorithm has a prerequisite that the array passed to it must
	 
// 	be already sorted in ascending order. This will not work on an unsorted array. The complexity of this algorithm is O(log(n)).
