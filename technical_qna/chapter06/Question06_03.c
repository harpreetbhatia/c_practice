#include <stdlib.h>
#include <stdio.h>

	Mergesort(a, left, right)
	{

	if(left<right)
	{

	I=(left+right)/2; Mergesort(a,left, I); Mergesort(a,I+1,right); Merge(a,b,left,I,right); Copy(b,a,left,right);
	}
	}

	The merge would be something liks this merge(int a[], int b[], int c[], int m, int n)
	{

	int i, j, k; i = 0;
	j = 0;
	k = 0;
	while(i<=m && j<=n)
	{

	if(a[i] < a[j])
	{
	 



	}
	else
	{




	}
	k=k+1;
	}
	 
	c[k]=a[i]; i = i+1;





	c[k]=a[j]; j=j+1;
	 

	while(i<=m)
	c[k++]=a[i++];
	while(j<=n)
	c[k++]=a[j++];
	}
