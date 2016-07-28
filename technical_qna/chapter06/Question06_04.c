#include <stdlib.h>
#include <stdio.h>

// 	Here is the Bubble sort algorithm
	void bubble_sort(int a[], int n)
	{

	int i, j, temp;
	for(j = 1; j < n; j++)
	{

	for(i = 0; i < (n - j); i++)
	{

	if(a[i] >= a[i + 1])
	{

	//Swap a[i], a[i+1]
	 
	}
	}
	}
	}

// 	To improvise this basic algorithm, keep track of whether a particular pass results in any swap or not. If not, you can break out without wasting more cycles.
	void bubble_sort(int a[], int n)
	{

	int i, j, temp; int flag;
	for(j = 1; j < n; j++)
	{

	flag = 0;
	for(i = 0; i < (n - j); i++)
	{

	if(a[i] >= a[i + 1])
	{

	//Swap a[i], a[i+1] flag = 1;
	}
	}

	if(flag==0)break;
	}
	}

	This is the selection sort algorithm
	void selection_sort(int a[], int n)
	{

	int i, j, small, pos, temp;
	 
	for(i = 0; i < (n - 1); i++)
	{

	small = a[i]; pos   = i;
	for(j = i + 1; j < n; j++)
	{

	if(a[j] < small)
	{

	small = a[j]; pos   = j;
	}
	}

	temp = a[pos]; a[pos] = a[i]; a[i]   = temp;
	}
	}

	Here is the Quick sort algorithm
	int partition(int a[], int low, int high)
	{

	int i, j, temp, key; key = a[low];
	i  = low + 1; j = high; while(1)
	{

	while(i < high && key >= a[i])
	 
	i++;
	while(key < a[j]) j--;
	 
	if(i < j)
	{






	}
	else
	{







	}
	}
	}
	 



	temp = a[i]; a[i] = a[j]; a[j] = temp;





	temp = a[low]; a[low] = a[j]; a[j] = temp; return(j);
	 

	void quicksort(int a[], int low, int high)
	{

	int j;
	if(low < high)
	{

	j = partition(a, low, high); quicksort(a, low, j - 1); quicksort(a, j + 1, high);
	}
	 
	}
	int main()
	{

	// Populate the array a quicksort(a, 0, n - 1);
	}

	Here is the Insertion sort algorithm
	void insertion_sort(int a[], int n)
	{

	int i, j, item;
	for(i = 0; i < n; i++)
	{

	item = a[i]; j	= i - 1;
	while(j >=0 && item < a[j])
	{

	a[j + 1] = a[j]; j--;
	}

	a[j + 1] = item;
	}
	}
